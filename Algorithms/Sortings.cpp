// merge sort
// quicksort from left, mid, right

// all are given

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1);
    vector<int> R(n2);
    
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
        
    for(int j=0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
    
}

void mergesort(vector<int>& arr, int left, int  right){
    if(left < right){
        int mid = left + (right - left)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void print(vector<int> arr){
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl << endl;
}

int partitionHigh(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    
    int i = low - 1;
    
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[high]);
    
    return i+1;
}

int partitionLow(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    
    int i = low + 1;
    int j = high;
    
    while(i <= j){
        while(i <= high && arr[i] <= pivot) i++;
        while(j > low && arr[j] > pivot) j--;
        
        if(i < j) 
            swap(arr[i], arr[j]);
    }
    
    swap(arr[low], arr[high]);
    return j;
}

int partitionMid(vector<int>& arr, int low, int high){
    int mid = low + (high - low)/2;
    swap(arr[low], arr[mid]);
    
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    
    while( i <= j){
        while(i <= high && arr[i] <= pivot) i++;
        while(j > low && arr[j] > pivot) j--;
        
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partitionMid(arr, low, high);
        
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main() {
    vector<int> arr = {5,3,4,1,2,7,6};
    
    // mergesort(arr, 0, arr.size()-1);
    print(arr);
    
    // arr = {5,3,4,1,2,7,6};
    quicksort(arr, 0, arr.size()-1);
    print(arr);
    
    
    return 0;
}
