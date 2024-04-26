class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> frequency;
        int count = 0;

        // Count the frequency of each number
        for (int num : nums) {
            frequency[num]++;
        }

        // For each frequency, calculate the number of identical pairs it contributes
        for (auto it: frequency) {
            if (it.second > 1) {
                // If there are n occurrences of the number, it contributes n choose 2 pairs
                count += (it.second * (it.second - 1)) / 2;
            }
        }

        return count;
    }
};
