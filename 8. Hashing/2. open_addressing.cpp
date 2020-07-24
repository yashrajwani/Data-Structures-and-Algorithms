#include <iostream>
using namespace std;

class HashTable
{
    const int MAX_SIZE;
    int *table;
    const int DELETE_FLAG;
    const int EMPTY_FLAG;
    const int hash_type;
    int size;
public:
    HashTable (int s, int htype=0) : MAX_SIZE(s), size(0), DELETE_FLAG(-2), EMPTY_FLAG(-1), hash_type(htype)
    {
        table = new int [MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; ++i)      table[i] = EMPTY_FLAG;
    }
    ~HashTable ()
    {
        delete[] table;
    }
    int h (int key)
    {
        //primary hash function
        return key % MAX_SIZE;
    }
    int hash (int key, int idx=0)
    {
        //argument hash_type defines which probing to use
        switch (hash_type)
        {
            //linear probing
            case 0:
                return h(h(key) + idx);
            
            //quadratic probing
            case 1:
                return h(h(key) + idx*idx);

            //double hashing
            case 2:
                int relative_prime = (11 != MAX_SIZE) ? 11 : 7;
                return h(h(key + idx*(relative_prime-(key % relative_prime))));       //check notes for better explanation
                //two hash functions are used (relative_prime-(key % relative_prime) is IInd hash function
                //relative prime so that every free slot can be probed 
        }
    }

    bool search (int key);
    void insert (int key);
    void remove (int key);
};

int main ()
{
    HashTable table(100,2);        //table with 10 buckets
    for (int i = 0; i < 20; ++i)     table.insert(i);
    cout << "10 in hash table: "<< boolalpha <<table.search(10) << endl;
    cout << "20 in hash table: "<< boolalpha <<table.search(20) << endl;
    table.remove(10);
    cout << "10 in hash table: "<< boolalpha <<table.search(10) << endl;
    
    return 0;
}

bool HashTable::search (int key)
{
    int h = hash(key);
    int i = h, idx = 0;
    while (table[i] != EMPTY_FLAG)
    {
        if (table[i] == key)      return true;
        i = hash(key, ++idx);
        if (i == h)     break;
    }
    return false;
}

void HashTable::insert (int key)
{
    if (size == MAX_SIZE)
    {
        cout << "MAX SIZE of Table exceeded";
        exit(-1);
    }
    int h = hash(key);
    int i = h, idx = 0;
    while (table[i] != EMPTY_FLAG && table[i] != DELETE_FLAG && table[i] != key)
    {
        i = hash(key, ++idx);
    }
    if (table[i] == key)      return;
    else
    {
        ++size;
        table[i] = key;
    }
}

void HashTable::remove (int key)
{
    int h = hash(key);
    int i = h, idx = 0;
    while (table[i] != EMPTY_FLAG)
    {
        if (table[i] == key)
        {
            table[i] = DELETE_FLAG;
            size--;
            //cout << "removed" <<key;
            return;
        }
        i = hash(key, ++idx);
        if (i == h)     break;
    }
}

