int binarysearch(vector<int> &arr, int k) {
    int s = 0;
    int e = arr.size() - 1;
    
    while(s <= e){
        int mid = s + (e-s)/2;
        
        if(arr[mid] == k)
            return mid;
            
        if(arr[mid] < k)
            s = mid + 1;
            
        else
            e = mid - 1;
    }
    return -1;
}
