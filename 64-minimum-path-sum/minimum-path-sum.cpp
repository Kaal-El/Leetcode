class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return INT_MAX;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int right = dfs(i, j + 1, grid, dp);
        int down = dfs(i + 1, j, grid, dp);
        return dp[i][j] = min(right, down) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return dfs(0, 0, grid, dp);
    }
};
