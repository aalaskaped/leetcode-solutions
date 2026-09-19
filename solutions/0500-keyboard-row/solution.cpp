class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;

        int letterToRow[] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2,
                             2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};

        for (const string& word : words) {
            int targetRow = letterToRow[tolower(word[0]) - 'a'];
            bool isValid = true;

            for (int i = 1; i < word.length(); ++i) {
                if (letterToRow[tolower(word[i]) - 'a'] != targetRow) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                result.push_back(word);
            }
        }

        return result;
    }
};

