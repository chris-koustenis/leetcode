from typing import List

# class Solution:
#     def reverseWords(self, s: str) -> str:
#         return " ".join(reversed(s.split()))
    
# Manual implementation without using built-in functions
class Solution:
    def reverseWords(self, s: str) -> str:
        ans = ""
        N = len(s)
        word = ""
        i = 0
        while i < N:
            while i < N and s[i] != " ":
                word += s[i]
                i += 1
            
            if len(word) > 0:
                if len(ans) == 0:
                    ans = word
                else:
                    ans = word + " " + ans
                word = ""
            
            while i < N and s[i] == " ":
                i += 1
                
        return ans

            

s = Solution()
print(s.reverseWords("the sky is blue"))  # Output: "blue is sky the
print(s.reverseWords("  hello world  "))  # Output: "world hello"
print(s.reverseWords("a good   example"))  # Output: "example good a"

