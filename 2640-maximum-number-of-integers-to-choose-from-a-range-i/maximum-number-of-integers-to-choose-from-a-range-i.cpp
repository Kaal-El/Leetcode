class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> set(banned.begin(),banned.end());
        int sum=0,count=0;
        for(int i=1;i<=n;i++)
        {
            if(set.find(i)==set.end() && maxSum>=sum+i)
            {
                sum+=i;
                count++;

            }
        }
        return count;
    }
};