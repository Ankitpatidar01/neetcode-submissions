class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;

        for(int i = 0 ; i < k ; i++){
            sum += arr[i];

        }

        int count =0;

       if((double)sum / (double)k >= threshold){
        count++;
       }


       for(int i = k ; i < arr.size() ; i++){
         sum += arr[i];
         sum -= arr[i- k];
if((double)sum / (double)k >= threshold){
        count++;
       }

       }

       return count;
    }
};