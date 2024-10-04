#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void print(vector<int> arr){
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high]; // last index
    int i = low-1;
    
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}


void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        
        int pivot = partition(arr, low, high);
        
        print(arr);
        
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main() {
     vector<int> arr = {10, 3, 8, 9, 7, 5, 4, 6, 2, 1}; // Sample vector

    cout << "Unsorted array: ";
    print(arr);

    quickSort(arr, 0, arr.size() - 1); // Call the QuickSort function

    cout << "Sorted array: ";
    print(arr);

    return 0;
}
