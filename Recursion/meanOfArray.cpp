// it is generall way, first found a sum of array then return the float,
// but whenever index becomes 0 then return sum / totalCount;
float meanOfArray(vector<int> arr, int i){
    if(i == arr.size()-1)
        return arr[i];
    
    float sum = arr[i] + meanOfArray(arr, i+1);
    
    if(i == 0)
        return float(sum / arr.size());
    
    return float(sum);
}


// here applied a formula
// Mean(n−1)×(n−1)+A[n−1] / n
float findMean(vector<int> arr, int n) 
{ 
    if (n == 1) 
        return float(arr[n-1]); 
    else
        return float(findMean(arr, n-1) * (n-1) + arr[n-1])    / n; 
} 
