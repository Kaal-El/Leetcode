class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long val = 0;
        map<double , long long> mp;
        
        for (int i = 0; i < rectangles.size(); i++) {
            double a = (rectangles[i][0]) / double(rectangles[i][1]);
            mp[a]++;
        }
        for (auto it : mp) {
                val += (it.second) * (it.second - 1) / 2;

        }
        
        return val;
    }
};
