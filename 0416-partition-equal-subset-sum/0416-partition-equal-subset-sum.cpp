class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the total sum is odd, we can't partition it into two equal sums
        if (totalSum % 2 != 0) return false;

        int halfSum = totalSum / 2;
        vector<bool> dp(halfSum + 1, false);
        dp[0] = true; // We can always achieve sum of 0

        for (int num : nums) {
            for (int j = halfSum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[halfSum];
    }
};
