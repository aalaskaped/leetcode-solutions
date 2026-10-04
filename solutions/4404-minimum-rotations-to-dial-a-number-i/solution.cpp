class Solution {
public:
    int minRotations(string s) {
        int cur = 0 , ans = 0;

        for(char c : s){
            int d = c - '0';
            int diff = abs(cur - d);
            ans+= min(diff , 10-diff);
            cur = d;
        }
        return ans;
    }
};
