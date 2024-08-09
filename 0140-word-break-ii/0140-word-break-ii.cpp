class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<vector<string>> dp(n + 1);  // DP array to store possible sentences
        dp[0] = {""};  // Base case: empty string
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (dp[j].size() > 0 && dict.find(word) != dict.end()) {
                    for (string str : dp[j]) {
                        dp[i].push_back((str.empty() ? "" : str + " ") + word);
                    }
                }
            }
        }
        return dp[n];  // Return all possible segmented sentences
    }
};