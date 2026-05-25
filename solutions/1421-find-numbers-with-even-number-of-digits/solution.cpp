class Solution  {
public:
    int findNumbers(vector<int>& nums) {
        int count =0 ;
        int digit =0 ;
        for (int i =0 ; i < nums.size(); i++)
        {
            while ( nums[i]>0 )
            {
            nums[i] = nums[i]/10;
            count ++;
            }
            if (count % 2 == 0)
            digit ++;
            else
            count  = 0;
           
            
        }
        return digit ;
    }
    
};
