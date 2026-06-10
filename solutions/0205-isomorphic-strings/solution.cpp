class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> kTOv{};
        unordered_map<char, char> vTOk{};
        if (s.size() != t.size())
            return false;
        for (int p = 0; p < s.size(); p++) {
            if (kTOv.find(s[p]) != kTOv.end()) {
                if (kTOv[s[p]] != t[p])
                    return false;
            }
            kTOv[s[p]] = t[p];

            if (vTOk.find(t[p]) != vTOk.end()) {
                if (vTOk[t[p]] != s[p])
                    return false;
            }
            vTOk[t[p]] = s[p];
        }

        return true;
    }
};
