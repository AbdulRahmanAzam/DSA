#include <iostream>
using namespace std;

void solve(int n, char from, char to, char aux){
    if(n == 1){
        cout << "move " << n << "  " << from << " -> " << to << endl << endl;
        return;
    }
    
    solve(n-1, from, aux, to);
    
    cout << "move " << n << "  " << from << " -> " << to << endl;
    
    solve(n-1, aux, to, from);
        
}

int main(){
    int n = 3;
    char from = 'F';
    char to = 'T';
    char aux = 'A';
    solve(n, from, to, aux);
}
