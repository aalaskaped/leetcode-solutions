class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> freq;
        for (int c : nums1){
        freq[c]++;
        }
        for (int t: nums2) {
            if (freq[t] > 0) {
                ans.push_back(t);
                freq[t]--;
            }
        }

        return ans;
    }
};
