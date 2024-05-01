class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans;
        int count=0;
        for(int i=0;i<word.size();i++)
        {
            ans.push_back(word[i]);
            count++;
            if(word[i]==ch)
            {
                reverse(ans.begin(),ans.end());
                break;
            }
        }
        
        for(int i=count;i<word.size();i++)
        {
            ans.push_back(word[i]);
        }
        return ans;
        
    }
};