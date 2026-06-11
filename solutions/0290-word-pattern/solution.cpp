class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        stringstream ss(s);

        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        unordered_map<char, string> kTOv{};
        unordered_map<string, char> vTOk{};
        if (pattern.size() != words.size())
            return false;
        for (int p = 0; p < pattern.size(); p++) {
            if (kTOv.find(pattern[p]) != kTOv.end()) {
                if (kTOv[pattern[p]] != words[p])
                    return false;
            }
            kTOv[pattern[p]] = words[p];

            if (vTOk.find(words[p]) != vTOk.end()) {
                if (vTOk[words[p]] != pattern[p])
                    return false;
            }
            vTOk[words[p]] = pattern[p];
        }

        return true;
    }
};

