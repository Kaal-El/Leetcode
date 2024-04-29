class Solution {
public:
    int mod = 0;
    int solve(int i,int j,int &m,int &n,int &k,vector<vector<int>> &g,vector<vector<vector<int>>> &dp,int sum){
        if(i<0||j<0||i>=m||j>=n)return 0;
        if(i==m-1&&j==n-1){
            sum = (sum+g[i][j])%k;
            if(sum%k==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][sum] != -1){
            return dp[i][j][sum];
        }
        return dp[i][j][sum%k] = (solve(i+1,j,m,n,k,g,dp,(sum+g[i][j])%k)+solve(i,j+1,m,n,k,g,dp,(sum+g[i][j])%k))%mod;;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        mod = 1e9+7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int> > > dp(m, vector<vector<int> >(n, vector<int>(k+1,-1)));
        return solve(0,0,m,n,k,grid,dp,0);
    }
};