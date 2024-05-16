class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.back()==' ')
        {
            s.pop_back();
        }
        int count=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==' ') break;
            count++;
        }
        return count;
    }
};