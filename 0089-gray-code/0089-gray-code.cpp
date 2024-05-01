class Solution {
public:
    void fn(vector<int> &result,bitset<32> &set,int k){
        if(k==0){
            result.push_back(set.to_ulong());
        }else{
            fn(result,set,k-1);
            set.flip(k-1);
            fn(result,set,k-1);
        }
    }
    vector<int> grayCode(int n) {
        vector<int> result;
        bitset<32> set;
        fn(result,set,n);
        return result;
    }
};