class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dup(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dup[n - 1][i] = grid[n - 1][i];
        }
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int ans = INT_MAX;
                for (int newcol = 0; newcol < n; newcol++) {
                    if(newcol!=col)
                    {
                        ans=min(ans,dup[row+1][newcol]);
                    }
                }
                dup[row][col]=ans+grid[row][col];
            }
        }
        int sol=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sol=min(sol,dup[0][i]);
        }
        return sol;
    }
};