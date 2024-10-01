#include <iostream>
using namespace std;

int Tailfibo(int n, int a = 0, int b = 1){
    if(n == 1)
        return a;
        
    return Tailfibo(n-1, b, a+b);
}

int NonTailfibo(int n){
    if(n <= 2)
        return n-1;
        
    return NonTailfibo(n-2) + NonTailfibo(n-1);
}

int main(){
    cout << "The Tail fibo of n = 8 is: " << Tailfibo(8);
    
    cout << "\n\nThe Non Tail fibo of n = 8 is: " << NonTailfibo(8);
}





