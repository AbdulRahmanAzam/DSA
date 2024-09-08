#include <iostream>

using namespace std;

int main () {
    string** hall = new string*[5];

    for(int i = 0; i < 5; ++i) {
        hall[i] = new string[i + 4];

        for(int j = 0; j < i + 4; ++j) {
            cout << "Enter attendee's name for row " << i + 1 << ", seat " << j + 1 << " : ";
            cin >> hall[i][j];
        }
    }

    cout << endl << "Seating Arrangement" << endl;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < i + 4; ++j) {
            cout << hall[i][j] << "\t";
        }
        cout << endl;
    }

    for(int i = 0; i < 5; ++i) {
        delete [] hall[i];
    }
    delete [] hall;
    
    return 0;
}
