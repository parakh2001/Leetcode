class Solution {
public:
    int dp[1001];
    
    bool game(int n)
    {
        if (n == 1) {
            return (0);
        }
        if (dp[n] != -1) {
            return (dp[n]);
        }
        for (int x = 1; x < n; x++) {
            if (n % x == 0 && !game(n - x)) {
                return (dp[x] = 1);
            }
        }    
        return (dp[n] = 0);
    }
    
    bool divisorGame(int n) 
    {
        memset(dp, -1, sizeof(dp));
        return game(n);
    }
};