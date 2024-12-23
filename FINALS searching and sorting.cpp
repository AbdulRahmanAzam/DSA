#include <bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>& arr, int key){
    int s = 0;
    int e = arr.size() - 1;
    int mid = (e-s)/2 + s;

    while(s <= e){
        if(arr[mid] == key)
            return mid;

        if(arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
}

int interpolationSearch(vector<int>& arr, int key){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high && arr[low] <= key & arr[high] <= key){
        int pos = low + ((key - arr[low]) / arr[high] - arr[low]) * (high - low);

        if(arr[pos] == key)
            return pos;
        
        if(arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}



// SORTING
// --------------------------------------MIN HEAP-----------------------------
void minHeapify(vector<int>& heap, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int n = heap.size();

    if(left < n && heap[left] < heap[smallest])
        smallest = left;
    else if(right < n && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i){
        swap(heap[smallest], heap[i]);
        minHeapify(heap, smallest);
    }
}

void buildMinHeap(vector<int>& heap){
    int n = heap.size();
    for(int i = n / 2 -1; i >= 0; i++){
        minHeapify(heap,i);
    }
}


// --------------------------------------MAX HEAP-----------------------------
void maxHeapify(vector<int>& heap,int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if(left < n && heap[left] > heap[largest])
        largest = left;
    if(right < n && heap[right] > heap[largest])
        largest = right;

    if(largest != i){
        swap(heap[largest], heap[i]);
        maxHeapify(heap,n, largest);
    }
}

void buildMaxHeap(vector<int>& heap){
    int n = heap.size();
    for(int i = n / 2 - 1; i >= 0; i--){
        maxHeapify(heap,n, i);
    }
}
// --------------------------------------HEAP SORT-----------------------------
void heapsort(vector<int>& heap){
    int n = heap.size();

    buildMaxHeap(heap);

    // extract elements from heap one by one
    for(int i = n - 1; i > 0; i--){
        swap(heap[0], heap[i]);

        // heapify the reduced heap
        maxHeapify(heap, i, 0);
    }
}



