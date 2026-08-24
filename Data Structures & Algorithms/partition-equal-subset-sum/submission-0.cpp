class Solution {
public:
    bool solve(vector<int>& nums , int index , int sum , int totalSum , vector<vector<int>>& dp){
        if(totalSum == sum){
            return sum;
        }

        if(dp[sum][totalSum] != -1) return dp[sum][totalSum];

        if(index >= nums.size()) return false;

        bool incl = solve(nums , index + 1 , sum + nums[index] , totalSum - nums[index] , dp);
        bool excl = solve(nums , index + 1 , sum , totalSum , dp);

        return dp[sum][totalSum] = incl || excl;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        
        for(int i =  0 ; i < nums.size() ; i++){
            totalSum += nums[i];
        }

        vector<vector<int>>dp(totalSum + 1 , vector<int>(totalSum + 1 , -1));

        return solve(nums , 0 , 0 , totalSum , dp);
    }
};
