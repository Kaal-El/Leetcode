class Solution {
public:
    int dfs(int m,int n,int i,int j,vector<vector<int>>& dp)
    {
        if(i==m-1 and j==n-1)
        {
            return 1;
        }
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int right=dfs(m,n,i+1,j,dp);
        int down=dfs(m,n,i,j+1,dp);
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int count=0;
        count=dfs(m,n,0,0,dp);
        return count;  
    }
};