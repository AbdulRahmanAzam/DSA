#include <iostream>
#include <vector>
#include <string>
using namespace std;

int binarySearch(vector<int> arr, int key){
    int s = 0;
    int e = arr.size()-1;
    
    while(s <= e){
        int mid = (e-s)/2 + s;
        
        if(arr[mid] == key)
            return mid;
            
        if(arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int sum(int n){
    if(!n)
        return n;
    return n + sum(n-1);
}


int decimaltobinary(int n){
    if(!n)
        return n; 
        
    return decimaltobinary(n/2) * 10 + (n%2);    
}

// void decimaltobinary(int n){
//     if(!n)
//         return;
        
//     decimaltobinary(n/2);
//     cout << n%2;
//     return;
// }

int countOnes(int n){
    if(!n)
        return n;
        
    return (n % 2 + countOnes(n/2));
}

// float meanOfArray(vector<int> arr, int i){
//     if(i == arr.size()-1)
//         return arr[i];
    
//     float sum = arr[i] + meanOfArray(arr, i+1);
    
//     if(i == 0)
//         return float(sum / arr.size());
    
//     return float(sum);
// }

float findMean(vector<int> arr, int n) 
{ 
    if (n == 1) 
        return float(arr[n-1]); 
    else
        return float(findMean(arr, n-1) * (n-1) + arr[n-1])    / n; 
} 

int sumOfArray(vector<int>arr, int i = 0){
    if(i == arr.size())
        return 0;
        
    return arr[i] + sumOfArray(arr,  i + 1);
}

int lengthOfString(string s){
    if(s.empty())
        return 0;
        
    // it removes the first character
    return 1 + lengthOfString(s.substr(1));
}

string reverseString(string s, int i = 0){
    if(i == s.size()/2)
        return s;
    
    swap(s[s.size() - i - 1], s[i]);
    
    return reverseString(s, i + 1);
}

bool checkPalindrome(string s, int i = 0){
    if(i == s.size())
        return true;
    
    return s[i] == s[s.size() - 1 - i] ? checkPalindrome(s, i + 1) : false;
}

void reverseFibonacci(int n, int a, int b){
    if(n <= 2)
        return;
    
    reverseFibonacci(n, b, a+b);
    
    cout << a << " ";
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Number of 1's in binary representation of " << 28 << " is: " << countOnes(28) << endl << endl;
    
    
    cout << "Sum of natural numbers is: "<< sum(10) << endl << endl;
    
    cout << "Decimal to binary: " << decimaltobinary(20) << endl << endl;
    
    cout << "Mean of Array: " << findMean(arr, arr.size()) << endl << endl;
    
    cout << "Sum of Array: " << sumOfArray(arr) << endl << endl;
    
    cout << "Length of String: " << lengthOfString("hello Bro") << endl << endl; 
    
    cout << "Reverse String: " << reverseString("string") << endl << endl;
    
    cout << "Check Palindrome of String: " << checkPalindrome("kiaik") << endl << endl;
    
    cout << "Reverse Fibonacci: " << endl << endl;   
    reverseFibonacci(5, 0 , 0);
}















