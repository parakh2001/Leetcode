class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int> res;
        for(auto it:mp){
            if(it.second!=2){
                res.push_back(it.first);
            }
        }
        return res;
    }
};