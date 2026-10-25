class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<int> v;
        long long total = 0;

        for (int num : nums) {
            total += num;
            string t = to_string(num);
            sort(t.begin(), t.end(), greater<char>());
            v.push_back(stoi(t) - num);
        }
        sort(v.begin(), v.end(), greater<int>());

        for (int i = 0; i < k; i++)
            total += v[i];

        return total;
    }
};
