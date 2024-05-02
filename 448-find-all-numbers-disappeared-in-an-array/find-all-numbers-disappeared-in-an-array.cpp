class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> set(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=1;i<=nums.size();i++)
        {
            if(set.find(i)==set.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};