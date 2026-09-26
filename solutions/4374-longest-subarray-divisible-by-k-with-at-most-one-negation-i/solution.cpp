class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int doubled = ((2LL * nums[j]) % k + k) % k;
                seen.insert(doubled);

                int remainder = (sum % k + k) % k;

                if (remainder == 0 || seen.count(remainder)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
