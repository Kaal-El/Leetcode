class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i>=grid.size()||j>=grid[0].size()) return INT_MAX;
        if(i==grid.size()-1 and j==grid[0].size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int right=dfs(i,j+1,grid,dp);
        int down=dfs(i+1,j,grid,dp);
        return dp[i][j]=min(right,down)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int val=dfs(0,0,grid,dp);
        return val;
        
    }
};