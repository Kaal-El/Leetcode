class Solution {
public:
    int max1;
    int n;

    void solve(int idx, vector<int>& score, vector<string> &words, int curr, vector<int> &freq) {
        max1 = max(max1, curr);
        if (idx >= n) return;

        vector<int> dup = freq;
        int j = 0;
        int temp = curr;
        bool canForm = true;

        while (j < words[idx].size()) {
            char ch = words[idx][j];
            dup[ch - 'a']--;
            temp += score[ch - 'a'];
            if (dup[ch - 'a'] < 0) {
                canForm = false;
                break;
            }
            j++;
        }

        if (canForm) {
            solve(idx + 1, score, words, temp, dup);
        }
        solve(idx + 1, score, words, curr, freq);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        max1 = 0;
        n = words.size();
        for (char ch : letters) {
            freq[ch - 'a']++;
        }
        solve(0, score, words, 0, freq);
        return max1;
    }
};
