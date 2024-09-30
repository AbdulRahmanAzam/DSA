#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

void sortRecursive(vector<int>& arr, int i = 0, int j = 0){
    int n = arr.size();
    if(i == n-1)
        return;
        
    if(arr[j+1] < arr[j]){
        swap(arr[j+1], arr[j]);
    }
        
    if(j == n-1)  
        sortRecursive(arr, i+1, 0);
    else
        sortRecursive(arr, i, j+1);
}

void sort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        bool flag = false;
        
        for(int j = 0; j < n-1; j++){
            
            if(arr[j+1] < arr[j]){
                swap(arr[j+1], arr[j]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}

void print(vector<int> arr){
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl << endl;
}

int main(){
    vector<int> arr = {5,2,4,8,65,2,1,6,3,0,4,12,76,34,6,2,8,1};
    sortRecursive(arr);
    print(arr);
}








