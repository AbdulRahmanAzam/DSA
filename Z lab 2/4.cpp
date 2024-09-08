#include <iostream>

using namespace std;

int main () {
    float** gpa = new float*[4];
    int totalCourses[] = {3, 4, 2, 1};
    float val = 1.0;

    for(int i = 0; i < 4; ++i) {
        gpa[i] = new float[totalCourses[i]];

        for(int j = 0; j < totalCourses[i]; ++j, val += 0.33) {
            gpa[i][j] = val;
        }
    }

    string dep[] = {"SE", "AI", "CS", "DS"};
    for(int i = 0; i < 4; ++i) {
        cout << "GPA of the core courses for " << dep[i] << " department" << endl;
        for(int j = 0; j < totalCourses[i]; ++j) {
            cout << gpa[i][j] << "\t";
        }
        cout << endl << endl;
    }

    for(int i = 0; i < 4; ++i) {
        delete[] gpa[i];
    }
    delete[] gpa;
    
    return 0;
}
