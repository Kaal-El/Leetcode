class Solution {
public:
    int count;
    int K;
    void solve(int idx,vector<int> &nums,map<int,int> &mp)
    {
        if(idx>=nums.size())
        {
            count++;
            return;
        }
        solve(idx+1,nums,mp);
        if(!mp[nums[idx]-K] &&!mp[nums[idx]+K])
        {
            mp[nums[idx]]++;
            solve(idx+1,nums,mp);
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        count=0;
        K=k;
        map<int,int> mp;
        solve(0,nums,mp);
        return count-1;
    }
};