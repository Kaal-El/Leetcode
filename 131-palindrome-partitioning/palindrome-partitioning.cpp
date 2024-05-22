class Solution {
public:
    bool ispalindrome(string s)
    {
        int left=0;
        int right=s.size()-1;
        while(left<right)
        {
            if(s[left++]!=s[right--])return false;
        }
        return true;
    }
    void helper(string s,vector<vector<string>> &ans, vector<string> arr)
    {
        if(s.size()==0)
        {
            ans.push_back(arr);
        }
        for(int i=0;i<s.size();i++)
        {
            string dup=s.substr(0,i+1);
            if(ispalindrome(dup))
            {
                arr.push_back(dup);
                helper(s.substr(i+1),ans,arr);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;
        helper(s,ans,arr);
        return ans;
    }
};