class Solution {
public:
int solve(string& ring, string& key, int i, int j, vector<vector<int>>& dp) {
    int m = ring.size();
    int n = key.size();
    if (i >= n) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = 0; k < m; k++) {
        if (ring[k] == key[i]) {
            int dup = min(abs(j - k), m - abs(j - k));
            ans = min(ans, 1 + dup + solve(ring, key, i + 1, k, dp));
        }
    }
    return dp[i][j] = ans;
}
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(key.size()+1,vector<int>(ring.size()+1,-1));
        return solve(ring,key,0,0,dp);
        
    }
};