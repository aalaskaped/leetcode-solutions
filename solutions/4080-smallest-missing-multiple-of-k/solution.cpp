class Solution {
public:
    long long missingMultiple(vector<int>& nums, int k) {
        unordered_set<long long> s(nums.begin(), nums.end());
        long long ans = k;
        while (s.count(ans)) ans += k;
        return ans;
    }
};
