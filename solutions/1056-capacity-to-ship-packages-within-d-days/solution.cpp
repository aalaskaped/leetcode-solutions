class Solution {
public:
    int totDays(vector<int>& arr, int cap){
        int day = 1 ;
        int count = 0;
        int load = 0;
        for (int t = 0; t<arr.size(); t++){
           if( load + arr[t] > cap ){
            day += 1;
            load = arr[t];
           }
           else
           load += arr[t];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
      int low = *max_element(weights.begin(),weights.end());
      int high = accumulate(weights.begin(),weights.end(),0);
      while(low<=high){
        int mid = low + (high - low)/2;
        int nodays = totDays(weights,mid);
        if (nodays<=days){
            high = mid - 1;
        }
        else
        low = mid + 1;
      }
    return low ;
    }
};
