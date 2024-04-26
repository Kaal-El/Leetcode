class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> set(nums.begin(),nums.end());
        if(valueDiff==0 and nums.size()==set.size()) return false;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<=i+indexDiff && j<nums.size();j++)
            {
                if(abs(nums[i]-nums[j])<=valueDiff)
                {
                    return true;

                }
            }
        }
        return false;
    }
};