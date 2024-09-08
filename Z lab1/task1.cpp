// Competitor: Abdul Rahman Azam

#include <iostream>

using namespace std;

class Bank {
private:
    double* balance;

public:
    Bank() : balance(new double(0.0)) {}

    Bank(double temp) : balance(new double(temp)) {}

    Bank(const Bank& other) {
        balance = new double(*(other.balance));
    }

    double getBalance() const {
        return *balance;
    }

    void deduct(double amnt) {
        if (amnt <= *balance) {
            *balance -= amnt;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    ~Bank() {
        delete balance;
    }
};

int main() {
    Bank account1;
    cout << "Balance of account1: " << account1.getBalance() << endl;

    Bank account2(1000.0);
    cout << "Balance of account2: " << account2.getBalance() << endl;

    Bank account3 = account2;
    account3.deduct(200.0);
    cout << "Balance of account3 after deduction: " << account3.getBalance() << endl;
    cout << "Balance of account2: " << account2.getBalance() << endl;

    return 0;
}
