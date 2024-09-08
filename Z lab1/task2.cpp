#include <iostream>

using namespace std;

class Exam {
    string studentName, date;
    int* score;

    public:
        Exam(string studentName, string date, int score) : studentName(studentName), date(date), score(new int(score)) {}

        void setScore(int score) {
            *this->score = score;
        }

        void displayDetails() {
            cout << "Student Name : " << studentName << endl << "Date : " << date << endl << "Score : " << *score << endl;
        }

        ~Exam() {
            delete score;
        }
};

int main () {
    Exam student1("Umar", "19/8/2024", 85);
    Exam student2 = student1;

    cout << "Before changing any value" << endl << "Details of student 1" << endl;
    student1.displayDetails();

    cout << endl << "Details of student 2" << endl;
    student2.displayDetails();

    student2.setScore(90);

    cout << endl << "After changing the value of score of student 2" << endl << "Details of student 1" << endl;
    student1.displayDetails();

    cout << endl << "Details of student 2" << endl;
    student2.displayDetails();

    return 0;
}
