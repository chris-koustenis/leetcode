#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

class LFUCache
{
private:
    class Node
    {
    public:
        int key;
        int value;
        int freq;
        int tick;

        Node(int k, int v, int t) : key(k), value(v), freq(1), tick(t) {}
        
        bool operator<(const Node &other) const
        {
            if (freq != other.freq)
                return freq < other.freq;
            return tick < other.tick;
        }
    };
    const int capacity;
    int tick_counter;
    set<Node> cache;
    unordered_map<int, set<Node>::iterator> key_iterator_map;

public:
    LFUCache(int capacity) : capacity(capacity), tick_counter(0) {}
    ~LFUCache() {}
    // O(log N) time complexity
    int get(int key)
    {
        auto it = key_iterator_map.find(key);
        if (it != key_iterator_map.end())
        {
            // update frequency and move to correct position
            Node node = *it->second;
            cache.erase(it->second);
            
            node.freq++;
            node.tick = ++tick_counter;
            
            auto new_it = cache.insert(node).first;
            key_iterator_map[key] = new_it;
            
            return node.value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (capacity == 0) return;

        auto it = key_iterator_map.find(key);
        if (it != key_iterator_map.end())
        {
            // Key exists, update value and freq
            Node node = *it->second;
            cache.erase(it->second);
            
            node.value = value;
            node.freq++;
            node.tick = ++tick_counter;
            
            auto new_it = cache.insert(node).first;
            key_iterator_map[key] = new_it;
            return;
        }
        
        if (cache.size() == capacity) // Cache is full
        {
            // Evict the least frequently used item (first in set)
            auto lfu_it = cache.begin();
            key_iterator_map.erase(lfu_it->key);
            cache.erase(lfu_it);
        }
        
        // Insert the new key-value pair
        Node node(key, value, ++tick_counter);
        auto new_it = cache.insert(node).first;
        key_iterator_map[key] = new_it;
    }
};

int main()
{
    LFUCache LFUCache(2);
    LFUCache.put(1, 1);              // cache is {1=1}
    LFUCache.put(2, 2);              // cache is {1=1, 2=2}
    cout << LFUCache.get(1) << endl; // return 1
    LFUCache.put(3, 3);              // LFU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << LFUCache.get(2) << endl; // returns -1 (not found)
    LFUCache.put(4, 4);              // LFU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << LFUCache.get(1) << endl; // return -1 (not found)
    cout << LFUCache.get(3) << endl; // return 3
    cout << LFUCache.get(4) << endl; // return 4
    return 0;
}