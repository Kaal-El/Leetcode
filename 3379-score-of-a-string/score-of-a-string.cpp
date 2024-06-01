class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=1;i<s.size();i++)
        {
            sum+=abs(int(s[i])-int(s[i-1]));
        }
        return sum;
    }
};