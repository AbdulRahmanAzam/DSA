#include <iostream>
#include <vector>
#include <list>
using namespace std;

class LibraryCatalog {
    vector<list<int>> table;
    int capacity;

public:
    LibraryCatalog(int size) : capacity(size) {
        table.resize(capacity);
    }

    int hashFunction(int bookID) {
        return bookID % capacity;
    }

    void insert(int bookID) {
        int index = hashFunction(bookID);
        table[index].push_back(bookID);
    }

    bool search(int bookID) {
        int index = hashFunction(bookID);
        for (int id : table[index]) {
            if (id == bookID)
                return true;
        }
        return false;
    }

    void remove(int bookID) {
        int index = hashFunction(bookID);
        table[index].remove(bookID);
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Index " << i << ": ";
            for (int bookID : table[i]) {
                cout << bookID << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};


//  MAIN IS MADE BY GPT
int main() {
    LibraryCatalog catalog(10);

    // Insert books
    catalog.insert(101);
    catalog.insert(102);
    catalog.insert(103); // Author A
    catalog.insert(201);
    catalog.insert(202); // Author B
    catalog.insert(301);
    catalog.insert(302);
    catalog.insert(303);
    catalog.insert(304); // Author C

    cout << "Library Catalog after insertion:" << endl;
    catalog.display();

    // Search for books
    cout << "\nSearch results:" << endl;
    cout << "Book 101: " << (catalog.search(101) ? "Found" : "Not Found") << endl;
    cout << "Book 303: " << (catalog.search(303) ? "Found" : "Not Found") << endl;
    cout << "Book 999: " << (catalog.search(999) ? "Found" : "Not Found") << endl;

    // Remove books
    catalog.remove(101);
    catalog.remove(303);
    cout << "\nLibrary Catalog after deletion:" << endl;
    catalog.display();

    return 0;
}
