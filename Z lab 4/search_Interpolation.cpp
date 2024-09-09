int interpolationSearch(int arr[], int n, int x){
  int low = 0;
  int high = arr.size() - 1;
  
  while(low <= high  && k >= arr[low] && k <= arr[high]){
      int pos = low + ((high - low)/(arr[high] - arr[low]) * (k - arr[low]));
      
      if(arr[pos] == k)
          return pos;
      
      if(arr[pos] < k)
          low = pos + 1;
      
      else 
          high = pos - 1;
  }
  return -1;
}
