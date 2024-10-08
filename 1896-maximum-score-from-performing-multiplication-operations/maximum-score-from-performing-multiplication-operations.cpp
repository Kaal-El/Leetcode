class Solution {
public:
vector<vector<int>> dp;
    int solve(int i,int j , vector<int> &nums,vector<int> & multipliers )
    {
        if(j==multipliers.size())   return 0;
        if(dp[i][j]!=INT_MIN)   return dp[i][j];
        int left= solve(i+1,j+1,nums,multipliers)+ nums[i]*multipliers[j];
        int right=solve(i,j+1,nums,multipliers) +nums[(nums.size()-1)-(j-i)]*multipliers[j];
        return dp[i][j]=max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(), m=multipliers.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        int ans=solve(0,0,nums,multipliers);
        return  ans;        
    }
};