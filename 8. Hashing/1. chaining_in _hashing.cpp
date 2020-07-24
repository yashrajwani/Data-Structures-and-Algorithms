#include <iostream>
#include <list>
using namespace std;

class HashTable
{
    int BUCKET;
    list <int> *table;

public:
    HashTable (int b) : BUCKET(b)
    {
        table = new list <int> [BUCKET];
    }
    ~HashTable ()
    {
        delete[] table;
    }
    int hash (int key)
    {
        return key % BUCKET;
    }

    bool search (int key);
    void insert (int key);
    void remove (int key);
};

int main ()
{
    HashTable table(10);        //table with 10 buckets
    for (int i = 0; i < 20; ++i)     table.insert(i);
    cout << "10 in hash table: "<< boolalpha <<table.search(10) << endl;
    cout << "20 in hash table: "<< boolalpha <<table.search(20) << endl;
    table.remove(10);
    cout << "10 in hash table: "<< boolalpha <<table.search(10) << endl;
    
    return 0;
}

bool HashTable::search (int key)
{
    int i = hash(key);
    for (auto x : table[i])
        if (x == key)   return true;
    return false;
}

void HashTable::insert (int key)
{
    int i = hash(key);
    table[i].push_back(key);
}

void HashTable::remove (int key)
{
    int i = hash(key);
    table[i].remove(key);
}

