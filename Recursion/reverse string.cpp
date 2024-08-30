
#include <iostream>
#include <string>
using namespace std;

void print(string name, int i){
    if(i != -1){
        cout << name[i--] << " ";
        print(name, i);
    }
}

int main() {
    string name = "Abdul";
    print(name, name.length()-1);
}
