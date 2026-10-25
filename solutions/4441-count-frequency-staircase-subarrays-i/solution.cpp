class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            vector<int> f;
            int bad = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (!mp.count(x)) {
                    int p = f.size();
                    mp[x] = p;
                    f.push_back(1);
                    if (p != 0)
                        bad++;
                } else {
                    int p = mp[x];
                    if (f[p] != p + 1)
                        bad--;
                    f[p]++;
                    if (f[p] != p + 1)
                        bad++;
                }
                if (bad == 0)
                    ans++;
            }
        }
        return ans;
    }
};
