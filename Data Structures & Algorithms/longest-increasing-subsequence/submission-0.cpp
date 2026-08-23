class Solution {
public:
    int solve(int index , int prev , vector<int>& nums , vector<vector<int>>& dp){

        if(index >= nums.size()) return 0;

        if(dp[index][prev + 1] != -1) return dp[index][prev + 1];
        int incl = 0;
        if(prev == -1 || nums[index] > nums[prev]){
            incl = 1 + solve(index + 1 , index , nums , dp);
        }

        int excl = solve(index + 1, prev , nums , dp);

        return dp[index][prev + 1] = max(incl , excl);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<vector<int>>dp(n +1 , vector<int>(n + 1 , -1));

       return solve(0 , -1 , nums , dp);
    }
};
