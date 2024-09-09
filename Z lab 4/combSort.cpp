void combSort(vector<int>& arr){
    int n = arr.size();
    int gap = n;
    
    bool swapped = true;
    
    while(gap != 1 || swapped == true){
        gap = (gap*10/13) < 1 ? 1 : (gap*10/13);
        swapped = false;
        
        for(int i = 0; i < n - gap; i++){
            if(arr[i] > arr[i + gap]){
                swap(arr[i], arr[i+gap]);
                swapped = true;
            }
        }
    }
}
