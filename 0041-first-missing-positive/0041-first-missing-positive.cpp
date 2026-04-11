class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums) {
            if (num > 0) {
                s.insert(num);
            }
        }

        int i = 1;
        while (true) {
            if (s.find(i) == s.end()) {
                return i;
            }
            i++;
        }
    }
};