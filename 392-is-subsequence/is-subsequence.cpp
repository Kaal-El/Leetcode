#include <string>
#include <set>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = -1;
        for (int i = 0; i < s.size(); i++) {
            idx = t.find(s[i], idx + 1);
            if (idx == string::npos)
                return false;
        }
        return true;
    }
};
