// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void print2(int n){
    if(!n) return;
    print2(n-1);
    cout << n << " ";
}

void print1(int n){
    if(!n) return;
    cout << "work\n";
    print1(n-1);
    print2(n);
    cout << "\n";
    // cout << n << " ";
}

int main() {
    print1(5);
}
