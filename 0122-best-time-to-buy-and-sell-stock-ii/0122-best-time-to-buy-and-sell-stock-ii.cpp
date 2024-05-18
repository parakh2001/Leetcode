class Solution {
public:
        int maxProfitUtil(vector<int> &prices, int idx, int buy, vector<vector<int>> &dp) {
        int n = prices.size();
        if (idx == n) {
            return 0;
        }
        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }
        int profit = 0;
        if (buy) {
            // Option to buy the stock
            profit = max(-prices[idx] + maxProfitUtil(prices, idx + 1, 0, dp),
                         maxProfitUtil(prices, idx + 1, 1, dp));
        } else {
            // Option to sell the stock
            profit = max(prices[idx] + maxProfitUtil(prices, idx + 1, 1, dp),
                         maxProfitUtil(prices, idx + 1, 0, dp));
        }
        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxProfitUtil(prices, 0, 1, dp);
    }
};