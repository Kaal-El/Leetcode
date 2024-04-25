class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n));
        int count=1;
        int top=0,bottom=n-1,left=0,right=n-1;
        while(top<=bottom and left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                arr[top][i]=count;
                count++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                arr[i][right]=count;
                count++;
            }
            right--;
            if(left<=right)
            {
                for(int i=right;i>=left;i--)
                {
                    arr[bottom][i]=count;
                    count++;
                }
                bottom--;
            }
            if(top<=bottom)
            {
                for(int i=bottom;i>=top;i--)
                {
                    arr[i][left]=count;
                    count++;
                }
                left++;
            }
        }
        return arr;

        
    }
};