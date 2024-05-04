class Solution {
public:
    int numRescueBoats(vector<int>& p, int a) {
        sort(p.begin(),p.end());
        int l=0,r=p.size()-1;
        int ans=0;
        while(l<=r)
        {
            if(p[l]+p[r]<=a)
            {l++;
            }
                ans++;
                r--;
            

        }
        return ans;
    }
};