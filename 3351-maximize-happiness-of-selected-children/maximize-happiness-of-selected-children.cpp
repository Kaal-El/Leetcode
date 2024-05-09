class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.rbegin(), h.rend());
        long long count = 0;
        int i = 0;
        while (i < k) {
            if (h[i] <= 0) return count;
            count += h[i];
            if (i + 1 < h.size()) {
                h[i + 1] -= (i + 1);
            }
            i++;
        }
        return count;
    }
};
