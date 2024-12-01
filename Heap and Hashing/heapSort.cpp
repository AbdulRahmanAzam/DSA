// THIS IS IN INCREASING ORDER
// 1 2 3 4 5 ... 

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }

}

void heapSort(vector<int>& arr){
    int n = arr.size();

    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
