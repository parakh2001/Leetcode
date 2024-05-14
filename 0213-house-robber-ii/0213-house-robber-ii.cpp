class Solution {
public:
    int fn(vector<int> &nums, int idx, vector<int> &memo) {
        if (idx < 0) {
            return 0;
        }
        if (memo[idx] != -1) {
            return memo[idx];
        }
        int pickFirst = nums[idx] + fn(nums, idx - 2, memo);
        int dontPickFirst = fn(nums, idx - 1, memo);
        memo[idx] = max(pickFirst, dontPickFirst);
        return memo[idx];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);

        vector<int> memo1(nums1.size(), -1);
        vector<int> memo2(nums2.size(), -1);

        int result1 = fn(nums1, nums1.size() - 1, memo1);
        int result2 = fn(nums2, nums2.size() - 1, memo2);

        return max(result1, result2);
    }
};
