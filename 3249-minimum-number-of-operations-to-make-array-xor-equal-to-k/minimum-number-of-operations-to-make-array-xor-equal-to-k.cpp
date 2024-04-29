class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total=0;
        for(int &num:nums)
        {
            total^=num;
        }
        int diff=total^k;
        return __builtin_popcount(diff);
        
    }
};