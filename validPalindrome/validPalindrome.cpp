#include <string>
#include <cctype>
using namespace std;

// class Solution {
// public:
//     bool isPalindrome(string s) {
//          auto head = s.begin(), tail = s.end();
//         tail--;
//         for(;head < tail; head++, tail--){
//             while(! (*head <= 122 && *head >= 97) 
//             && !(*head <= 90 && *head >= 65) 
//             && !(*head <= 57 && *head >= 48) && head < tail)
//             head++;
//             while(! (*tail <= 122 && *tail >= 97) 
//             && !(*tail <= 90 && *tail >= 65) 
//             && !(*tail <= 57 && *tail >= 48) && head < tail)
//             tail--;
//             // Make them all lowercase
//             if(*head <= 90 && *head >= 65) *head += 32;
//             if(*tail <= 90 && *tail >= 65) *tail += 32;
//             if(*head != *tail) return false;
//         }
//         return true;
//     }
// };
// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0, right = s.size() - 1;
//         while (left < right) {
//             while (left < right && !isalnum(s[left])) left++;
//             while (left < right && !isalnum(s[right])) right--;
//             if (tolower(s[left]) != tolower(s[right])) {
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isPalindrome(string s) {
        auto left = s.begin();
        auto right = s.end();
        right--;
        while (left < right) {
            while (left < right && !isalnum(*left)) left++;
            while (left < right && !isalnum(*right)) right--;
            if (tolower(*left) != tolower(*right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};


int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(s);
    if (result) {
        printf("The string is a valid palindrome.\n");
    } else {                
        printf("The string is not a valid palindrome.\n");
    }
    return 0;
}