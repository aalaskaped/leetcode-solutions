class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int single = 0;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 != 0)
                mid -= 1;
            if (nums[mid] == nums[mid + 1])
                low = mid + 2;
            else
                high = mid;
            if (low == high) {
                single = low;
            }
        }
        return nums[single];
    }
};
