class Solution {
public:
void Sub(vector<int>& nums,vector<vector<int>>& ans,vector<int>& sub,int ind)
{
    ans.push_back(sub);
    for(int i=ind;i<nums.size();i++)
    {
        sub.push_back(nums[i]);
        Sub(nums,ans,sub,i+1);
        sub.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> sub;
        int ind=0;
        Sub(nums,ans,sub,ind);
        return ans;
        
    }
};