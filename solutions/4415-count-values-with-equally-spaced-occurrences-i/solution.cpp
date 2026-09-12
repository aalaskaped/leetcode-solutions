class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int count = 0;

        for (auto &p : mp) {
            vector<int> positions = p.second;

            if (positions.size() == 3) {
                if (positions[1] - positions[0] ==
                    positions[2] - positions[1]) {
                    count++;
                }
            }
        }

        return count;
    }
};
