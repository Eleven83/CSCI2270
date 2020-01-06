#include<iostream>
using namespace std;
#include<vector>

class Hash
{
    int hashTableSize;
    vector<int> *hashTable;

public:
    // Constructor
    Hash(int V);

    // inserts a key into hash table
    void insertItem(int key);

    // search a key in a Hash Table
    void searchItem(int key);

    // hash function to map a key to index
    int hashFunc(int key);

    void displayHash();
};

/*
Initialises a hash table of a given size.
*/
Hash::Hash(int n)
{
    this->hashTableSize = n;
    hashTable = new vector<int>[hashTableSize];
}

/*
Hash function to map a key to index.
*/
int Hash::hashFunc(int key)
{
    return (key % hashTableSize);
}

/*
Displays all the keys of the hash table.
*/
void Hash::displayHash()
{
  for (int i = 0; i < hashTableSize; i++)
  {
    cout << i;
    for (auto x : hashTable[i])
      cout << " --> " << x;
    cout << endl;
  }
}
