#include <iostream>

using namespace std;


int main(){
    // making a 2D array with 5 rows
    int **arr = new int*[5];
    int colIndex = 10;

    for(int i= 0;i < 5; i++){
        // changing column to 10 in each row
        arr[i] = new int[colIndex];
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < colIndex; j++){
            cout << "Row is : " << i+1 << " and col no is: " << j+1 << " Enter element: ";
            cin >> *(*(arr + i) + j);
        }
    }
}
