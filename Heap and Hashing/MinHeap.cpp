#include <bits/stdc++.h>
using namespace std; 

class MinHeap{
    public:
    vector<int> heap;

    void heapifyUp(int index){
        int parent = (index - 1) / 2;
        if(index > 0 && heap[index] < heap[parent]){ // only this is the difference
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index){
        int left = 2 * left + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if(left < heap.size() && heap[left] < heap[smallest]) // only this is the difference
            smallest = left;
        else if(right < heap.size() && heap[right] < heap[smallest]) // only this is the difference
            smallest = right;

        if(smallest != index){
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(int key){
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void deleteMin(){
        if(heap.empty()){
            cout << "Heap is empty" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void deleteKey(int key){
        int index = -1;
        for(int i = 0; i < heap.size(); i++){
            if(heap[i] == key){
                index = i;
                break;
            }
        }

        if(index == -1) {
            cout << "Not found" << endl;
            return;
        }

        swap(heap[index], heap.back());
        heap.pop_back();

        if(index < heap.size()){
            heapifyDown(index);
            heapifyUp(index);
        }
    }
    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};


int main() {
    MinHeap minHeap;

    // Insert values
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(20);
    minHeap.insert(2);

    cout << "MinHeap after insertions: ";
    minHeap.display();

    // Search values
    // cout << "Search 5: " << (minHeap.search(5) ? "Found" : "Not Found") << endl;
    // cout << "Search 15: " << (minHeap.search(15) ? "Found" : "Not Found") << endl;

    // Delete min
    minHeap.deleteMin();
    cout << "MinHeap after deleting min: ";
    minHeap.display();

    return 0;
}
