#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int x, int s, int e){
    if(s > e)
        return -1;
    
    int mid = (s+e)/2;
    
    if(arr[mid] == x)
        return mid;
        
    if(arr[mid] < x)
        return binarySearch(arr, x, mid + 1, e);
    else
        return binarySearch(arr, x, s, mid - 1);
    
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,11,14,16,18,20,23,25,37,58,78};
    
    int n = 23;
    cout << "The 23 is at index: " << binarySearch(arr, n, 0, arr.size()-1);
}





