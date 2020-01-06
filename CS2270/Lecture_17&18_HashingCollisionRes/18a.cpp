#include <iostream>
#include <list>

using namespace std;

class Hash
{
    int BUCKET; //Number of buckets
    //Pointer to an array containing buckets
    list<int> *table;
public:
    Hash(int V); //Constructor
    //Inserts a key in to the Hash table
    void insertItem(int x);
    //Deletes a key from the Hash table
    void deleteItem(int key);
    //Hash function to map values to keys
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    void displayHash();

};

Hash::Hash(int b)
{
    this->BUCKET=b;
    table=new list<int>[BUCKET];
}

//Inserts a key
void Hash::insertItem(int key)
{
    int index=hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    //get the hash index of the key
    int index=hashFunction(key);
    //Find the index position of the key in the list
    list<int>::iterator i;
    for(i=table[index].begin(); i!=table[index].end(); i++)
    {
        if(*i==key)
        {
            break;
        }
    }
    //If key is found in the hash table, remove it
    if(i!=table[index].end())
        table[index].erase(i);
}

//Function to display the hash table
void Hash::displayHash()
{
    for(int i=0; i<BUCKET; i++)
    {
        cout<<i;
        for(auto x : table[i])
        {
            cout<<" --> "<<x<<endl;
        }
    }
}

//Driver program
int main()
{
    //Array that contains keys to be mapped
    int a[]={15, 11, 27, 8, 12};
    int n=sizeof(a)/sizeof(a[0]); //a=4 bytes*5 elements = 20 and a[0]=4 bytes, Therefore, 20/4=5. n=5.

    //Insert the keys in to the hash table
    Hash h(7); //7 buckets in this hash table
    for(int i=0; i<n; i++)
    {
        h.insertItem(a[i]);
    }
    h.displayHash();
    cout<<" "<<endl;
    // //Delete 12 from the hash table
    // h.deleteItem(12);

    // //Displaythe hash table
    // h.displayHash();

    return 0;
}
