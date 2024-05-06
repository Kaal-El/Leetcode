class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> ans;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i][1]<b[0]) ans.push_back(a[i]);
            else if(a[i][0]>b[1]) 
            {
                ans.push_back(b);
                b=a[i];
            }
            else
            {
                b[0] = min(b[0], a[i][0]);
                b[1] = max(b[1], a[i][1]);
            }

        }
        ans.push_back(b);
        return ans;
        
    }
};