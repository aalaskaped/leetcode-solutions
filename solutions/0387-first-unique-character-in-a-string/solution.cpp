class Solution {
public:
    int firstUniqChar(string s) {
        map <char,int> freq;

        for (char c:s)
        {
            freq[c]++;
        }

        for (int t =0;t<s.size();t++)
        {
            if (freq[s[t]]==1)
            return t;
        }
  return -1; }
};
