class Solution {
public:
    char check(char c)
    {
        if(islower(c))return toupper(c);
        return tolower(c);
    }
    void solve(vector<string>& ans,string& temp,string &s,int idx)
    {
        int i=idx;
        if(idx>=s.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(s[i]);
        solve(ans,temp,s,i+1);
        temp.pop_back();
        
        if(isalpha(s[i]))
        {
            temp.push_back(check(s[i]));
            solve(ans,temp,s,i+1);
            temp.pop_back();
        }
       


    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp; 
        solve(ans,temp,s,0);
        return ans;
        
    }
};