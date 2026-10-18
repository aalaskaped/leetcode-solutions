class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int deletions = 0 ;
        int last = nums[0] ;

        for (int i = 1 ; i < nums.size() ; i++){
            if (nums[i] == last)
                deletions ++;
            else 
                last = nums[i] ;
        }
        return deletions ;
    }
};
