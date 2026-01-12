#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int check = 0;
        const int match_size = s.size();
        const int N = t.size();
        if(s.empty()) return true;
        for(int i = 0 ; i < N; ++i){
            if(N-i < match_size-check) return false;
            if(t[i] == s[check]){
                check++;
                if(check == match_size) return true;
            }
        }
        return false;
    }
};
int main(){

    Solution sol;
    string s = "abc";
    string t = "ahbgdc";
    bool result = sol.isSubsequence(s, t);
    // result should be true
    cout << (result ? "true" : "false") << endl;
    s = "axc";
    t = "ahbgdc";
    result = sol.isSubsequence(s, t);
    // result should be false
    cout << (result ? "true" : "false") << endl;

    return 0;
}