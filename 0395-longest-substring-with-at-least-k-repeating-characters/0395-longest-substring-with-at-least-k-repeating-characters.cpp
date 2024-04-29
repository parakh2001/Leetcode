class Solution {
public:
    int fn(string s, int k) {
	int n = s.length();
	int nums[256] = {0};
	int maxi = 0;
	for (int left = 0; left < n; left++) {
		memset(nums, 0, sizeof(nums));
		for (int right = left; right < n; right++) {
			nums[s[right] - 'a']++;
			bool valid = true;
			for (char c = 'a'; c <= 'z'; c++) {
				if (nums[c-'a']>0 && nums[c-'a']<k) {
					valid = false;
					break;
				}
			}
			if (valid) {
				maxi = max(maxi, right - left + 1);
			}
		}
	}
	return maxi;
}
    int longestSubstring(string s, int k) {
        return fn(s,k);
    }
};