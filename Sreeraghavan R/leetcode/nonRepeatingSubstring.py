class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq = {}
        len = 0
        max = 0
        for i in s:
            if i not in freq.keys():
                freq[i] = 1
                len += 1
            else:
                freq = {}
                if(len > max):
                    max = len
        return max