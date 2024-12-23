#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HashMap1 { // Separate Chaining
    int size;
    vector<vector<int>> table;

    int hashFunction(int key) {
        return key % size;
    }

    public:
        HashMap1(int size = 10) : size(size) {
            table.resize(size);
        }

        void insertItem(int key) {
            int index = hashFunction(key);
            table[index].push_back(key);
        }

        bool searchItem(int key) {
            int index = hashFunction(key);
            return find(table[index].begin(), table[index].end(), key) != table[index].end();
        }

        void deleteItem(int key) {
            int index = hashFunction(key);

            auto it = find(table[index].begin(), table[index].end(), key);
            if(it != table[index].end()) {
                table[index].erase(it);
            }
        }

        void displayTable() {
            for(int i = 0; i < table.size(); ++i) {
                cout << i << ": ";
                for(int j = 0; j < table[i].size(); ++j) {
                    cout << table[i][j] << ", ";
                }
                cout << endl;
            }
        }
};

class HashMap2 { // Linear Probing
    int currentlyFilled, size;
    vector<int> table;

    int hashFunction(int key) {
        return key % size;
    }

    float getLoadFactor() {
        return (float)currentlyFilled / size;
    }

    void rehash() {
        size *= 2;
        vector<int> newTable(size, -1);
        
        for(int& num : table) {
            if(num != -1) {
                int hash = hashFunction(num);
                for(int i = 0; i < size; ++i) {
                    int index = (hash + i) % size;
                    if(newTable[index] == -1) {
                        newTable[index] = num;
                        break;
                    }
                }
            }
        }
        table = newTable;
    }

    public:
        HashMap2(int size = 10) : currentlyFilled(0), size(size) {
            table.resize(size, -1);
        }

        void insertItem(int key) {
            int hash = hashFunction(key);
            for(int i = 0; i < size; ++i) {
                int index = (hash + i) % size;
                if(table[index] == -1) {
                    table[index] = key;

                    // If there is no need of rehash, comment these lines
                    ++currentlyFilled;
                    if(getLoadFactor() >= 0.75) {
                        rehash();
                    }

                    return;
                }
            }
        }

        bool searchItem(int key) {
            int hash = hashFunction(key);
            for(int i = 0; i < size; ++i) {
                int index = (hash + i) % size;
                if(table[index] == key) {
                    return true;
                }
            }
            return false;
        }

        void deleteItem(int key) {
            int hash = hashFunction(key);
            for(int i = 0; i < size; ++i) {
                int index = (hash + i) % size;
                if(table[index] == key) {
                    --currentlyFilled;
                    table[index] = -1;
                    return;
                }
            }
        }

        void displayTable() {
            for(int i = 0; i < size; ++i) {
                cout << i << ": ";
                if(table[i] != -1) {
                    cout << table[i];
                }
                cout << endl;
            }
        }
};

class HashMap3 { // Quadratic Probing
    int currentlyFilled, size;
    vector<int> table;

    int hashFunction(int key) {
        return key % size;
    }

    float getLoadFactor() {
        return (float)currentlyFilled / size;
    }

    void rehash() {
        size *= 2;
        vector<int> newTable(size, -1);
        
        for(int& num : table) {
            if(num != -1) {
                int hash = hashFunction(num);
                for(int i = 0; true; ++i) {
                    int index = (hash + i * i) % size;
                    if(newTable[index] == -1) {
                        newTable[index] = num;
                        break;
                    }
                }
            }
        }
        table = newTable;
    }

    public:
        HashMap3(int size = 10) : currentlyFilled(0), size(size) {
            table.resize(size, -1);
        }

        void insertItem(int key) {
            int hash = hashFunction(key);
            for(int i = 0; true; ++i) {
                int index = (hash + i * i) % size;
                if(table[index] == -1) {
                    table[index] = key;

                    // If there is no need of rehash, comment these lines
                    ++currentlyFilled;
                    if(getLoadFactor() >= 0.75) {
                        rehash();
                    }

                    return;
                }
            }
        }

        bool searchItem(int key) {
            int hash = hashFunction(key);
            for(int i = 0; true; ++i) {
                int index = (hash + i * i) % size;
                if(table[index] == key) {
                    return true;
                }
                if(i && index == hash) break;
            }
            return false;
        }

        void deleteItem(int key) {
            int hash = hashFunction(key);
            for(int i = 0; true; ++i) {
                int index = (hash + i * i) % size;
                if(table[index] == key) {
                    table[index] = -1;
                    --currentlyFilled;
                    return;
                }
                if(i && index == hash) break;
            }
        }

        void displayTable() {
            for(int i = 0; i < size; ++i) {
                cout << i << ": ";
                if(table[i] != -1) {
                    cout << table[i];
                }
                cout << endl;
            }
        }
};

class HashMap4 { // Double Hashing
    int currentlyFilled, size;
    vector<int> table;

    int hashFunction1(int key) {
        return key % size;
    }

    int hashFunction2(int key) {
        return 7 - key % 7;
    }

    float getLoadFactor() {
        return (float)currentlyFilled / size;
    }

    void rehash() {
        size *= 2;
        vector<int> newTable(size, -1);
        
        for(int& num : table) {
            if(num != -1) {
                int hash1 = hashFunction1(num);
                int hash2 = hashFunction2(num);
                for(int i = 0; true; ++i) {
                    int index = (hash1 + i * hash2) % size;
                    if(newTable[index] == -1) {
                        newTable[index] = num;
                        break;
                    }
                }
            }
        }
        table = newTable;
    }

    public:
        HashMap4(int size = 11) : currentlyFilled(0), size(size) {
            table.resize(size, -1);
        }

        void insertItem(int key) {
            int hash1 = hashFunction1(key);
            int hash2 = hashFunction2(key);
            for(int i = 0; true; ++i) {
                int index = (hash1 + i * hash2) % size;
                if(table[index] == -1) {
                    table[index] = key;

                    // If there is no need of rehash, comment these lines
                    ++currentlyFilled;
                    if(getLoadFactor() >= 0.75) {
                        rehash();
                    }

                    return;
                }
            }
        }

        bool searchItem(int key) {
            int hash1 = hashFunction1(key);
            int hash2 = hashFunction2(key);
            for(int i = 0; true; ++i) {
                int index = (hash1 + i * hash2) % size;
                if(table[index] == key) {
                    return true;
                }
                if(i && index == hash1) break;
            }
            return false;
        }

        void deleteItem(int key) {
            int hash1 = hashFunction1(key);
            int hash2 = hashFunction2(key);
            for(int i = 0; true; ++i) {
                int index = (hash1 + i * hash2) % size;
                if(table[index] == key) {
                    --currentlyFilled;
                    table[index] = -1;
                    return;
                }
                if(i && index == hash1) break;
            }
        }

        void displayTable() {
            for(int i = 0; i < size; ++i) {
                cout << i << ": ";
                if(table[i] != -1) {
                    cout << table[i];
                }
                cout << endl;
            }
        }
};

int main() {
    HashMap4 hashMap;

    // Insert keys
    vector<int> keysToInsert = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    for (int key : keysToInsert) {
        hashMap.insertItem(key);
    }

    cout << "Hash Table after insertion:\n";
    hashMap.displayTable();

    // Search for keys
    vector<int> keysToSearch = {30, 100};
    cout << "\nSearching for keys 30 and 100:\n";
    for (int key : keysToSearch) {
        cout << "Key " << key << ": " << (hashMap.searchItem(key) ? "Found" : "Not Found") << endl;
    }

    // Delete keys
    vector<int> keysToDelete = {20, 50};
    for (int key : keysToDelete) {
        hashMap.deleteItem(key);
    }

    cout << "\nHash Table after deletion:\n";
    hashMap.displayTable();

    // Insert more keys to trigger rehashing
    vector<int> keysToTriggerRehash = {95, 105, 115};
    for (int key : keysToTriggerRehash) {
        hashMap.insertItem(key);
    }

    cout << "\nHash Table after rehashing:\n";
    hashMap.displayTable();

    return 0;
}
