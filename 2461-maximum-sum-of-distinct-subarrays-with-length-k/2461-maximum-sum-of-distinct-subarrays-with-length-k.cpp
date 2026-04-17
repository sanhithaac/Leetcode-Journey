class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long maxSum = 0;
        long long windowSum = 0;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;
            windowSum += nums[right];

            while (mp[nums[right]] > 1 || (right - left + 1) > k) {
                mp[nums[left]]--;
                windowSum -= nums[left];
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }

            if ((right - left + 1) == k) {
                maxSum = max(maxSum, windowSum);
            }
        }

        return maxSum;
    }
};