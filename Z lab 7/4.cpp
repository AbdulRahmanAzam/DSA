#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int>& arr){
    int n = arr.size();
    
    int mx = arr[0];
    
    for(int i = 1; i < n; i++)
        if(arr[i] > mx)
            mx = arr[i];
    
    return mx;
};

void countSort(vector<int>& arr, int expe, bool ascending){
    int n = arr.size();
    
    vector<int> output(n);
    vector<int> count(10, 0);
    
    for(int i = 0; i < n; i++)
        count[(arr[i] / expe) % 10] += 1;
    
    
    if(ascending)
        for(int i = 1; i < 10; i++)
            count[i] += count[i-1];
    else
        for(int i = 8; i >= 0; i--)
            count[i] += count[i+1];
    
    
    for(int i = n-1; i >= 0 ; i--){
        output[count[(arr[i] / expe) % 10] - 1] = arr[i];
        count[(arr[i] / expe) % 10] -= 1;
    }
    
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
    
};

void radixSort(vector<int>& arr, bool ascending){
    int n = arr.size();
    int mx = getMax(arr);
    
    for(int expe = 1; mx / expe > 0; expe *= 10)
        countSort(arr, expe, ascending);
    
};

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5, 3};
    bool ascending = true;
    radixSort(arr, ascending);
    
    cout << "Ascending" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    
    ascending = false;
    radixSort(arr, ascending);
    cout << "\nDescending" << endl; 
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0; 
}
