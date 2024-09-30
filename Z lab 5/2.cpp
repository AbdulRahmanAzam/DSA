#include <iostream>
using namespace std;

int TailFact(int n, int ans = 1){
    if(n == 1)
        return ans;
    
    return TailFact(n-1, ans*n);
}

int NonTailFact(int n){
    if(n == 1)
        return 1;
        
    return n * NonTailFact(n-1);
}

int main(){
   cout << "Non tail factorial of 5: " << NonTailFact(5) << endl << endl;
   cout << "Tail Factorial of 5: " << TailFact(5) << endl;
}








