
// DOUBLE HASHING
int HashFunction(int key){
        return key % capacity;
    }

int secondaryHash(int index, int key){
    while(table[index] != -1 && table[index] != key){
        index = (index + (prime - (key % prime))) % capacity;
    }
    return index;
}


// SEPERATE CHAINING
void insert(int key){
    int index = hashFunction(key);
    Node* newNode = new Node(key);

    if(table[index] == nullptr){
        table[index] = newNode;
    }else {
        Node* temp = table[index];
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}



// REHASHING
void rehash(){
  int oldCapacity = capacity;
  vector<int> oldTable = table;

  capacity *= 2;
  table = vector<int>(capacity, -1);
  size = 0;

  for(int i= 0; i < oldCapacity; i++){
      if(oldTable[i] != -1)
          insert(oldTable[i]);
  } 
}

// LINEAR PROBING
int linearProbe(int index, int key){
    while(table[index] != -1 && table[index] != key){
        index = (index + 1) % capacity;
    }
    return index;
}

// QUADRATIC PROBING
int quadraticProbe(int index, int key){
    int i = 1;
    while(table[index] != -1 && table[index] != key){
        index = (index + i * i) % capacity;
        i++;
    }
    return index;
}


