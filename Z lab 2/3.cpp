#include <iostream>
#include <string>
using namespace std;

void print1(string arr[5][5]){
    for(int i = 0; i < arr[0][0].length(); i++){
        for(int j = 0;j < arr[0][0].length(); j++){
            cout<<arr[i][j] << " ";
        }
    }
}

int main(){
   string arr[5][5] = {
    {"", "*", "", "*","*"},
    {"*", "", "*", "", "*"},
    {"","*", "", "", ""},
    {"*", "", "", "", "*"},
    {"*", "*", "", "*", ""}
   };

   print1(arr);

   bool ans[5][5];


    for(int i = 0;i < 5; i++){
        for(int j = 0;j < 5; j++){
            for(int k = 0;k < 5; k++){
                if(arr[i][j] == "*" && arr[i][k] == "*" && j != k){
                    cout << "Common friends are = " << "i = " << i << " j = " << j << " k = " << k << endl;
                    ans[i][j] = true;
                }else{    
                    ans[i][j] = false;
                }
            }
        }
    }
}
