class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector <int> ans;
        for (auto i =nums.begin();i<nums.end(); i++)
        {
            ans.push_back(nums[*i]);
        }
        return ans;
    }
};
