class Solution {
public:
    bool fn(const string& str, const string& pattern, int i, int j,vector<vector<int>> &dp) {
        // if both strings are exhausted
        if (i < 0 && j < 0) {
            return true;
        }
        // if pattern is remaining
        if (j < 0 && i >= 0) {
            return false;
        }
        // if string is remaining
        if (i < 0 && j >= 0) {
            // Check if remaining pattern characters are all '*'
            for (int jj = 0; jj <= j; jj++) {
                if (pattern[jj] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        bool result;
        // if characters match or pattern has '?'
        if (pattern[j] == str[i] || pattern[j] == '?') {
            result = fn(str, pattern, i - 1, j - 1, dp);
        }
        // if pattern has '*'
        else if (pattern[j] == '*') {
            // * can match zero or more characters
            result = fn(str, pattern, i - 1, j, dp) || fn(str, pattern, i, j - 1, dp);
        }
        // if characters don't match
        else {
            result = false;
        }
        // memoize the result
        dp[i][j] = result;
        return result;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fn(s, p, s.length() - 1, p.length() - 1,dp);
    }
};
