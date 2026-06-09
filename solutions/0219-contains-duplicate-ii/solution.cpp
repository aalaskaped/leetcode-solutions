class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int , int > mp{};
         for (int t = 0 ; t<nums.size() ; t++ ){
           if (mp.find(nums[t]) != mp.end())
            {
            if ( t - mp[nums[t]] <= k)
               return true;
            }
             mp[nums[t]]=t;
        }
  return false;  }
};
