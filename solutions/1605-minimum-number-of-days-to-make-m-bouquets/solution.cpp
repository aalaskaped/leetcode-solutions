class Solution {
public:
    bool possible(vector<int>& arr, int mid, int m, int k) {
        int count = 0;
        int NoB = 0;
        for (int t = 0; t < arr.size(); t++) {
            if (mid >= arr[t])
                count++;
            else {
                NoB += (count / k);
                count = 0;
            }
        }
        NoB += (count / k);
        return (NoB >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
         if ((long long)m * k > bloomDay.size() )
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
       
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
