class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());

        if (min_val == max_val) return 0;

        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;

        vector<int> bucket_min(bucket_count, INT_MAX);
        vector<int> bucket_max(bucket_count, INT_MIN);
        vector<bool> used(bucket_count, false);

        // Fill buckets
        for (int num : nums) {
            int idx = (num - min_val) / bucket_size;
            bucket_min[idx] = min(bucket_min[idx], num);
            bucket_max[idx] = max(bucket_max[idx], num);
            used[idx] = true;
        }

        // Compute max gap
        int prev_max = min_val;
        int max_gap = 0;

        for (int i = 0; i < bucket_count; i++) {
            if (!used[i]) continue;

            max_gap = max(max_gap, bucket_min[i] - prev_max);
            prev_max = bucket_max[i];
        }

        return max_gap;
    }
};