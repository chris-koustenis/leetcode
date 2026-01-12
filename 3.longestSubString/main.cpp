#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int startOfSubStr = 0 ;
        int endOfSubStr = 0;
        const int n = s.length();

        if (n == 0) return 0;

        int max_sub_str = 0;
        int curr_sub_str = 0;
        unordered_map<char, int> hash_set; // to store the characters in the current window and their latest indices
        while(endOfSubStr < n){
            char new_char = s[endOfSubStr];
            auto it = hash_set.find(new_char);
            if (it != hash_set.end() && it->second >= startOfSubStr) {
                // Character already exists in the current window
                // Move the start of the window to the right of the previous occurrence
                startOfSubStr = it->second + 1;
            }
            hash_set[new_char] = endOfSubStr;
            max_sub_str = max(max_sub_str, endOfSubStr - startOfSubStr + 1);
           
            endOfSubStr++; // expand the window
        }
        return max_sub_str;
    }
};


int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;    // 1
    return 0;
}