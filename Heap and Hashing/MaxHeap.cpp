#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
    vector<int> heap;

    void heapifyUp(int index){
        int parent = (index - 1) / 2;
        
        if(index > 0 && heap[index] > heap[parent]){ // only this is the difference
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if(left < heap.size() && heap[left] > heap[index]) // only this is the difference
            smallest = left;
        else if (right < heap.size() && heap[right] > heap[index]) // only this is the difference
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

    void deleteMax(){
        if(heap.empty()){
            cout << "heap is emoptou" << endl;
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
};

int main(){

}
