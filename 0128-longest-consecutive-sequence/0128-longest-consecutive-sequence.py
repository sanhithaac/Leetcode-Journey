class Solution(object):
    def longestConsecutive(self, nums):
        s = set(nums)
        longest = 0
        for n in s:
            if n - 1 not in s:
                length = 1
                x = n + 1
                while x in s:
                    length += 1
                    x += 1
                if length > longest:
                    longest = length
        return longest

        