class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0;
        int far=0;
        int cur=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            far=max(far,nums[i]+i);
            if(cur==i)
            {
                count++;
                cur=far;
            }
        }
        return count;
    }
};