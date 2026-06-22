class Solution {
public:
    int subtractProductAndSum(int n) {
        int sub = 0;
        int sum = 0;
        int product = 1;
        while (n != 0) {
            int b = n % 10;
            sum += b;
            product *= b;
            n = n / 10;
        }

        return sub = product - sum;
    }
};
