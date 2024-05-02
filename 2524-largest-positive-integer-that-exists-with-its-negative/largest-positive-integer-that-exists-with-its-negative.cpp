class Solution {
public:
    int findMaxK(vector<int>& nums) {
      int ans = -1;
        set<int> Set(nums.begin(), nums.end());
        for (int it :Set) {
            if (Set.find(-it) != Set.end()) {
                ans =max(ans, it);
            }
        }
        return ans;
    }
};