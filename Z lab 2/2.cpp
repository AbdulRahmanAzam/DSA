#include <iostream>
#include <string>
using namespace std;

int main(){
   string arr[5][5] = {
    {"", "*", "", "*","*"},
    {"*", "", "*", "", "*"},
    {"","*", "", "", ""},
    {"*", "", "", "", "*"},
    {"*", "*", "", "*", ""}
   };

   bool ans[5][5];


    for(int i = 0;i < 5; i++){
        for(int j = 0;j < 5; j++){
            for(int k = 0;k < 5; k++){
                if(arr[i][j] == "*" && arr[i][k] == "*" && j != k){
                    cout << "i = " << i << " j = " << j << " k = " << k << endl;
                    ans[i][j] = true;
                }else{    
                    ans[i][j] = false;
                }
            }
        }
    }
    
    for(int i=0;i < 5; i++){
        for(int j=0;j < 5; j++){
            if(ans[i][j])
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}
