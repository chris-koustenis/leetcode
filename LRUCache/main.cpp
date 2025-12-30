#include <list>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <cassert>
using namespace std;

class LRUCache
{
private:
    class Node
    {
    private:
        int key;
        int value;

    public:
        Node(int k, int v) : key(k), value(v) {}
        ~Node() {}
        bool operator==(const Node &other) const
        {
            return key == other.key;
        }
        int getKey() const { return key; }
        int getValue() const { return value; }
        void setValue(int v) { value = v; }
    };
    const int capacity;
    list<Node> cache;                                          // array to track the next LRU item to be evicted by key
    unordered_map<int, list<Node>::iterator> key_iterator_map; // map to store key and its iterator in LRU list

public:
    LRUCache(int capacity) : capacity(capacity) {}
    ~LRUCache() {}
    // O(1) time complexity
    int get(int key)
    {
        auto it = key_iterator_map.find(key);
        if (it != key_iterator_map.end())
        {
            // Key exists, move to front
            cache.splice(cache.begin(), cache, it->second);
            return it->second->getValue();
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = key_iterator_map.find(key);
        if (it != key_iterator_map.end())
        {
            // Key exists, update value and move to front
            cache.splice(cache.begin(), cache, it->second);
            it->second->setValue(value);
            return;
        }
        if (cache.size() == capacity) // Cache is full
        {
            // Evict the least recently used item
            int lru_key = cache.back().getKey();
            cache.pop_back();
            key_iterator_map.erase(lru_key);
        }
        
        // Insert the new key-value pair
        cache.push_front(Node(key, value));
        key_iterator_map[key] = cache.begin(); // put the iterator on the new element at
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);              // cache is {1=1}
    lRUCache.put(2, 2);              // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << endl; // return 1
    lRUCache.put(3, 3);              // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << endl; // returns -1 (not found)
    lRUCache.put(4, 4);              // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << endl; // return -1 (not found)
    cout << lRUCache.get(3) << endl; // return 3
    cout << lRUCache.get(4) << endl; // return 4
    return 0;
}