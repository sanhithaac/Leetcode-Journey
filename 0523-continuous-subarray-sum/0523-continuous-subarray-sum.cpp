class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1; 
        int prefix = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            int remainder = prefix % k;
            if (remainder < 0) remainder += k;

            if (mp.find(remainder) != mp.end()) {
                if (i - mp[remainder] >= 2) {
                    return true;
                }
            } else {
                mp[remainder] = i;
            }
        }

        return false;
    }
};