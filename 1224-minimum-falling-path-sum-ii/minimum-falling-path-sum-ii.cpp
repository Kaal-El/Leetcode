class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dup(n, vector<int>(n, INT_MAX));
        int newcol1=-1;
        int newcol2=-1;
        for (int i = 0; i < n; i++) {
            dup[n - 1][i] = grid[n - 1][i];
            if(newcol1==-1 or grid[n-1][i]<grid[n-1][newcol1])
            {
                newcol2=newcol1;
                newcol1=i;
            }
            else if(newcol2==-1 or grid[n-1][i]<grid[n-1][newcol2])
            {
                newcol2=i;
            }
        }
        for (int row = n - 2; row >= 0; row--) {
            int col1=-1;
            int col2=-1;
            for (int col = 0; col < n; col++) {
                if(col!=newcol1)
                {
                    dup[row][col]=dup[row+1][newcol1]+grid[row][col];
                }
                else
                {
                    dup[row][col]=dup[row+1][newcol2]+grid[row][col];
                }
                if(col1==-1 or dup[row][col]<=dup[row][col1])
                {
                    col2=col1;
                    col1=col;
                }
                else if(col2==-1 or dup[row][col]<dup[row][col2])
                {
                    col2=col;
                }
                }
                newcol1=col1;
                newcol2=col2;
            }
        
        int sol=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sol=min(sol,dup[0][i]);
        }
        return sol;
    }
};