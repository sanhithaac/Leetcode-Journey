class Solution {
public:
    int mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        int mid = (l + r) / 2;
        int count = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, r);

        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j]) j++;
            count += (j - (mid + 1));
        }

        vector<int> temp;
        int i = l, k = mid + 1;

        while (i <= mid && k <= r) {
            if (nums[i] <= nums[k]) temp.push_back(nums[i++]);
            else temp.push_back(nums[k++]);
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (k <= r) temp.push_back(nums[k++]);

        for (int i = l; i <= r; i++) nums[i] = temp[i - l];

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};