class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n==1) return 0;
        for(int i=2;i<n;i++)
        {
            long x1=coordinates[i-2][0],y1=coordinates[i-2][1];
            long x2=coordinates[i-1][0],y2=coordinates[i-1][1];
            long x3=coordinates[i][0], y3=coordinates[i][1];
            if((y3-y2)*(x2-x1)!=(y2-y1)*(x3-x2)) return false;

        }
        return true;
        
    }
};