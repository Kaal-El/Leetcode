class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> sol(26,0);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int current=s[i]-'a';
            int ma=0;
            int left=max(0,current-k);
            int right=min(25,current+k);
            for(int j=left;j<=right;j++)
            {
                ma=max(ma,sol[j]);
            }
            sol[current]=max(sol[current],ma+1);
            ans=max(ans,sol[current]);
        }
         return ans;   
    }

};