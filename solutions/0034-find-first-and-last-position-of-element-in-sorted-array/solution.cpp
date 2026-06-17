class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       
        vector<int> ans(2) ;
        auto it = lower_bound(nums.begin(), nums.end(), target);
        ans[0] = it - nums.begin();
        if ( it == nums.end() ||*it != target ){
            return {-1,-1};
        }
        auto t = upper_bound(nums.begin(), nums.end(), target) - 1;
        ans[1] = t - nums.begin();
        return ans;
    }
};
