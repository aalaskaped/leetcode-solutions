class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count = 0;
        int finalInvalid = -1;

        int i = 0;
        while (i < nums.size()) {
            if (nums[i] < minK || nums[i] > maxK)
                finalInvalid = i;
            else
                count += i - finalInvalid;
            i++;
        }
        return count;
    }
};
