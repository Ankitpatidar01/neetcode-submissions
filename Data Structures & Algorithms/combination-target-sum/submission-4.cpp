class Solution {
public:
    void solve(vector<int>& nums, int index,
               vector<int>& temp,
               vector<vector<int>>& ans,
               int target) {

        if(target < 0) return;

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (index >= nums.size())
            return;

    
        temp.push_back(nums[index]);
        solve(nums, index, temp, ans,
                  target - nums[index]);
        temp.pop_back();

        solve(nums, index + 1, temp, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, 0, temp, ans, target);

        return ans;
    }
};