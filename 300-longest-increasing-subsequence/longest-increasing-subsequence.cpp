class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 1;
        }
        int n=nums.size();
        int big=0;
        vector<int> ans(n,1);
        for(int i=1;i<n;i++)
        {
            int greater=0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    greater=max(greater,ans[j]);
                }
            }
            ans[i]=max(greater+1,ans[i]);
            big=max(big,ans[i]);
        }
        return big;
        
    }
};