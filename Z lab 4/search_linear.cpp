vector<int> linearSearch(vector<int>& arr, int key) {
    for(int i = 0;i < arr.size(); i++){
        if(arr[i] == key)
            return i;
    }
}
