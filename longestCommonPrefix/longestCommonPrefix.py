from typing import List

def get_length(e: str):
    return len(e)

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        if len(strs) == 0:
            return result
        strs.sort(key=get_length)
        prev = strs[0]
        for i in range(0,len(strs[0])):
            for word in strs[1:]:
                if word[i] == prev[i]:
                    pass
                else:
                    return result
            result += prev[i]
        return result
    