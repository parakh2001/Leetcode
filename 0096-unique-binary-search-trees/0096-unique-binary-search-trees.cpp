class Solution {
public:
    int numTrees(int n) {
        return round(exp(lgamma(n + n + 1) - lgamma(n + 2) - lgamma(n + 1)));
    }
};