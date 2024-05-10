class Solution {
public:
int fun(vector<int> &nums, int idx, vector<int> &memo) {
    if (idx < 0) {
        return 0;
    }
    if (memo[idx] != -1) {
        return memo[idx];
    }
    int pick = nums[idx] + fun(nums, idx - 2, memo);
    int nonpick = fun(nums, idx - 1, memo);
    memo[idx] = max(pick, nonpick);
    return memo[idx];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> memo(n, -1);
    return fun(nums, n - 1, memo);
}
};