#include <bits/stdc++.h>
using namespace std;
// --------------------------------------------------------------- 706. Design HashMap -----------------------------------------------------------------------------
class Bucket
{
private:
    // Vector to store key-value pairs
    vector<pair<int, int>> bucket;

public:
    // Constructor to initialize an empty bucket
    Bucket() {}

    // Method to Get the value corresponding to a key
    int get(int key)
    {
        // Iterate through each key-value pair in the bucket
        for (pair<int, int> &keyValue : bucket)
        {
            // If the key matches the provided key, return the corresponding value
            if (keyValue.first == key)
                return keyValue.second;
        }
        // If the key is not found, return -1
        return -1;
    }

    // Method to Update the value associated with a key
    void update(int key, int value)
    {
        // Iterate through each key-value pair in the bucket
        for (pair<int, int> &keyValue : bucket)
        {
            // If the key matches the key of the current key-value pair
            if (key == keyValue.first)
            {
                // Update the value of the key-value pair
                keyValue.second = value;
                return;
            }
        }
        // If the key is not found in the bucket, add it along with its value
        bucket.push_back(make_pair(key, value));
    }
    // Method to Remove a key-value pair from the bucket
    void remove(int key)
    {
        // Iterate through each key-value pair in the bucket
        vector<pair<int, int>>::iterator itr;
        for (itr = bucket.begin(); itr != bucket.end(); itr++)
        {
            // If the key matches the key of the current key-value pair
            if (key == itr->first)
            {
                // Delete the key-value pair from the bucket
                bucket.erase(itr);
                return;
            }
        }
    }
};
class MyHashMap
{
public:
    // Number of key spaces
    int keyspaces;
    // Vector of buckets
    vector<Bucket> buckets;

    // Constructor to initialize the hash map with a prime number of key spaces
    MyHashMap()
    {
        keyspaces = 2069;
        // Resize the vector of buckets
        buckets.resize(keyspaces);
    }

    // Function to add a key-value pair to the hash map
    void put(int key, int value)
    {
        // Calculate the hash key
        int hashKey = key % keyspaces;
        // Update the bucket at the hashed key with the key-value pair
        buckets[hashKey].update(key, value);
    }

    // Function to retrieve the value associated with a given key from the hash map
    int get(int key)
    {
        // Calculate the hash key
        int hashKey = key % keyspaces;
        // Return the value associated with the key from the corresponding bucket
        return buckets[hashKey].get(key);
    }

    // Function to Remove a key-value pair from the hash map given a key
    void remove(int key)
    {
        // Calculate the hash key
        int hashKey = key % keyspaces;
        // Remove the key-value pair from the corresponding bucket
        buckets[hashKey].remove(key);
    }
};
// int main()
// {
//     cout << string(35, '-') << endl;
//     MyHashMap hashMap;
//     hashMap.put(1, 1);
//     hashMap.put(2, 2);
//     cout << hashMap.get(1) << endl;
//     cout << hashMap.get(3) << endl;
//     hashMap.put(2070, 1);
//     cout << hashMap.get(2) << endl;
//     hashMap.remove(2);
//     cout << hashMap.get(2) << endl;
//     cout << string(35, '-');
// }
// ------------------------------------------------------------------------
class HashMap
{
    vector<vector<pair<int, int>>> buckets;
    const int size = 2069;

public:
    /** Initialize your data structure here. */
    HashMap()
    {
        buckets.resize(size);
    }
    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int index = key % size;
        vector<pair<int, int>> &bucket = buckets[index];
        for (auto itr = bucket.begin(); itr != bucket.end(); itr++)
        {
            if (itr->first == key)
            {
                itr->second = value;
                return;
            }
        }
        bucket.push_back(make_pair(key, value));
    }
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int index = key % size;
        vector<pair<int, int>> &bucket = buckets[index];
        for (auto itr = bucket.begin(); itr != bucket.end(); itr++)
        {
            if (itr->first == key)
            {
                return itr->second;
            }
        }
        return -1;
    }
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int index = key % size;
        vector<pair<int, int>> &bucket = buckets[index];
        for (auto itr = bucket.begin(); itr != bucket.end(); itr++)
        {
            if (itr->first == key)
            {
                bucket.erase(itr);
                return;
            }
        }
    }
};

int main()
{
    cout << string(35, '-') << endl;
    cout << string(35, '-');
    return 0;
}