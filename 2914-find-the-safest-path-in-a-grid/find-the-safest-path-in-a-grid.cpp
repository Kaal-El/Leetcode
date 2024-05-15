#pragma GCC optimize("O3", "unroll-loops")
// union find class with rank
class UnionFind {
    vector<int> root, rank;

public:
    UnionFind(int n) : root(n), rank(n, 1) {
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        if (x == root[x])
            return x;
        else
            return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)
            return;
        if (rank[rX] > rank[rY])
            swap(rX, rY);
        root[rX] = rY;
        if (rank[rX] == rank[rY])
            rank[rY]++;
    }
    bool connected(int x, int y) { return Find(x) == Find(y); }
};

class Solution {
public:
    using int2 = pair<int, int>; //(i, j)
    int n;
    inline int2 to2d(int x) {
        auto [i, j] = div(x, n);
        return {i, j};
    }
    inline int to1d(int i, int j) { return i * n + j; }

    const int d[5] = {0, 1, 0, -1, 0};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return 0; // very special case
        queue<int2> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.emplace(i, j);
                } 
                else
                    grid[i][j] = -1;
            }
        }
        vector<int2> L1[800];
        fill(L1, L1 + 800, vector<int2>());
        int dist = 0;
        while (!q.empty()) {
            int qz = q.size();
            for (int a = 0; a < qz; a++) {
                auto [i, j] = q.front();
                q.pop();
                for (int b = 0; b < 4; b++) {
                    int r = i + d[b], c = j + d[b + 1];
                    if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != -1)
                        continue;
                    grid[r][c] = dist + 1;
                    q.emplace(r, c);
                    L1[dist + 1].emplace_back(r, c);
                }
            }
            dist++;
        }

        UnionFind G(n * n);
        for (int dd = dist - 1; dd >= 0; dd--) {
            if (L1[dd].empty())
                continue;
            for (auto& [i, j] : L1[dd]) {
                for (int b = 0; b < 4; b++) {
                    int r = i + d[b], c = j + d[b + 1];
                    if (r < 0 || r >= n || c < 0 || c >= n)
                        continue;
                    if (grid[r][c] >= dd)
                        G.Union(to1d(i, j), to1d(r, c));
                }
            }
            if (G.connected(0, n * n - 1))
                return dd;
        }
        return 0;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();