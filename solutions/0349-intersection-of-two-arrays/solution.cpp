class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> s;
        unordered_set <int> result;
         for (int c : nums1){
            s.insert(c);
         }
        for (int c : nums2){
            if (s.find(c)!=s.end())
            result.insert(c);
        }
        vector<int> ans( result.begin() , result.end() );

  return ans;  }
};
