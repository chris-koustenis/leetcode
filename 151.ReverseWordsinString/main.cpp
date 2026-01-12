#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        const int N = s.length();
        string word;
        for (int i = 0; i < N; ++i){
            word = "";
            while(s[i] != ' ' && i < N) word = word + s[i++];
            if(!word.empty()) ans = word + ' ' + ans;
        }
        if(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};


/*
O(1) space solution
class Solution {
public:
    string reverseWords(string s) {
        // Convert string to char array for in-place modifications
        // (we operate directly on the string)
        
        // Step 1: Reverse entire string
        reverseRange(s, 0, (int)s.size() - 1);

        // Step 2: Reverse each word
        reverseWordsInPlace(s);

        // Step 3: Clean up spaces and return the cleaned string
        return cleanSpaces(s);
    }

private:
    void reverseRange(string& str, int left, int right) {
        while (left < right) {
            char temp = str[left];
            str[left++] = str[right];
            str[right--] = temp;
        }
    }

    void reverseWordsInPlace(string& s) {
        int n = (int)s.size();
        int start = 0;
        for (int end = 0; end < n; ++end) {
            // Find the end of the current word
            if (s[end] == ' ') {
                reverseRange(s, start, end - 1);
                start = end + 1; // Move to the start of the next word
            }
        }
        // Reverse the last word
        reverseRange(s, start, n - 1);
    }

    string cleanSpaces(string s) {
        int n = (int)s.size();
        int i = 0, j = 0;

        while (j < n) {
            // Skip spaces
            while (j < n && s[j] == ' ') j++;
            // Copy non-space characters
            while (j < n && s[j] != ' ') s[i++] = s[j++];
            // Skip spaces to reach the next word, add only one space if there's a next word
            while (j < n && s[j] == ' ') j++;
            if (j < n) s[i++] = ' ';
        }
        s.resize(i);
        return s;
    }
};
*/
int main (){
    Solution sol;
    string s = "  hello world  ";
    string result = sol.reverseWords(s);
    // result should be "world hello"
    cout << "\"" << result << "\"" << endl;

    s = "a good   example";
    result = sol.reverseWords(s);
    // result should be "example good a"
    cout << "\"" << result << "\"" << endl;

    s = "  Bob    Loves  Alice   ";
    result = sol.reverseWords(s);
    // result should be "Alice Loves Bob"
    cout << "\"" << result << "\"" << endl;

    s = "Alice does not even like bob";
    result = sol.reverseWords(s);
    // result should be "bob like even not does Alice"
    cout << "\"" << result << "\"" << endl;

    return 0;
}