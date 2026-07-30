class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        number = None
        for num in nums:
            if count ==0:
                number = num
            if num == number:
                count += 1
            else: 
                count -= 1

        return number