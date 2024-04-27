class Solution {
public:
    int yesRec(int i, int j, string& ring, string& key, vector<vector<int>>& dp)
    {
        if (i >= key.size())
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;
        for (int k = 0; k < ring.size(); k++)
        {
            if (key[i] == ring[k])
            {
                int dist = min(abs(j - k), (int)ring.size() - abs(j - k));
                res = min(res, 1 + dist + yesRec(i + 1, k, ring, key, dp));
            }
        }

        return dp[i][j] = res;
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(key.size() + 1, vector<int> (ring.size() + 1, -1));

        return yesRec(0, 0, ring, key, dp);
    }
};