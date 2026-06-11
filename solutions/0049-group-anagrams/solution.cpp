class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int t = 0; t < strs.size(); t++) {

            string temp = strs[t];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[t]);
        }
        vector<vector<string>> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
