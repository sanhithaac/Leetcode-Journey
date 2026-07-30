class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        if not strs:
            return ""
        prefix =""
        for i in range(len(strs[0])):

            current = strs[0][i]
            for word in strs:
                if i==len(word) or word[i]!=current:
                    return prefix
            prefix += current

        return prefix




        