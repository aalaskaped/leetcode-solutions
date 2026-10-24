class Solution {
public:
    int countMagicalPairs(string s) {
      int n = s.size();
        long long ans = 0;
        for (int j = 0 ; j < n-1; j++){
            int left[27] = {} , right[27] = {};
            int f[26] = {} , d = 0;

            for (int i = j; i >= 0; i--){
                if (!f[s[i] - 'a']++)
                d++;
                left[d]++;
            }
            fill(f,f+26,0);
            d=0;
            for (int k = j + 1; k < n; k++){
                if (!f[s[k] - 'a']++)
                d++;
                right[d]++;
            }
            for (int x = 1; x <= 26 ; x++){
                ans+= left[x]*right[x];
            }
        }
        return ans;
    }
};
