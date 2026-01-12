#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        // stack to store characters
        int N = s.length();
        vector<char> char_stack;
        

        for(int i = 0; i < N/2; ++i){
            char c = s[i];
            char_stack.push_back(c);

        }
    }
};

int main(){
    Solution s;
    string str = "babad";
    string res = s.longestPalindrome(str);
    cout << "Longest Palindromic Substring of " << str << " is: " << res << endl;
    return 0;
}