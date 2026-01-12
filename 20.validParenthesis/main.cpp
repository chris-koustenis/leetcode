#include <iostream>
#include <stack>
#include <string>
using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for (const char c : s){
//             switch (c)
//             {
//                 case ')':
//                     if(st.empty() || st.top() != '(' ) return false;
//                     else st.pop();
//                     break;
//                 case '}':
//                     if(st.empty() || st.top() != '{' ) return false;
//                     else st.pop();
//                     break;
//                 case ']':
//                     if(st.empty() || st.top() != '[' ) return false;
//                     else st.pop();
//                     break;
//                 default:
//                     st.push(c);
//             }
//         }
//         if (st.empty())
//             return true;
//         else
//             return false;
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (const char c : s){
            if (c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                if (st.empty()) return false;
                char top = st.top();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')){
                    return false;
                }
                st.pop();
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};



int main() {
    Solution solution;
    string s = "{[()]}";
    if (solution.isValid(s)) {
        cout << "The string of parentheses is valid." << endl;
    } else {
        cout << "The string of parentheses is not valid." << endl;
    }
    return 0;
}