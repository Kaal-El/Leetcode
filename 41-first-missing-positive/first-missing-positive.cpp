class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> set(nums.begin(),nums.end());
        int max1=0;
        for(int i=1;i<=nums.size();i++)
        {
            if(set.find(i)==set.end())
            {
                return i;
            }
            max1=max(max1,i);
        }

        return max1+1;
    }
};