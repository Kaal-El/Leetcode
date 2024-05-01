class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n=stockPrices.size();
        if(n<=1)return 0;
        int count=1;
        sort(stockPrices.begin(),stockPrices.end());
        for(int i=2;i<n;i++)
        {
            long x1=stockPrices[i-2][0],y1=stockPrices[i-2][1];
            long x2=stockPrices[i-1][0],y2=stockPrices[i-1][1];
            long x3=stockPrices[i][0],y3=stockPrices[i][1];
            if((y3-y2)*(x2-x1)!=(y2-y1)*(x3-x2))
            {
                count++;
            }

        }
        return count;
        
    }
};