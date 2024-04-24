class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowbeg=0,rowend=matrix.size()-1,colbeg=0,colend=matrix[0].size()-1;
        while(rowbeg<=rowend and colbeg<=colend)
        {
            for(int i=colbeg;i<=colend;i++)
            {
                ans.push_back(matrix[rowbeg][i]);
            }
            rowbeg++;
            for(int i=rowbeg;i<=rowend;i++)
            {
                ans.push_back(matrix[i][colend]);
            }
            colend--;
            if(rowend>=rowbeg)
            {
                for(int i=colend;i>=colbeg;i--)
                {
                    ans.push_back(matrix[rowend][i]);
                }
                rowend--;
            }

            if(colbeg<=colend)
            {
                for(int i=rowend;i>=rowbeg;i--)
                {
                    ans.push_back(matrix[i][colbeg]);
                }
                    colbeg++;
            }

        }
        return ans;
    }
};