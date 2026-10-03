class Solution {
public:
     void solve(vector<int>& nums ,int index , set<vector<int>>& st , vector<int>temp){

        if(index >= nums.size()){
            st.insert(temp);
            return;
        }


        temp.push_back(nums[index]);
        solve(nums , index + 1, st , temp);
        temp.pop_back();

        solve(nums , index + 1, st , temp);
     }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>st;

        solve(nums , 0 , st , {});

         vector<vector<int>>ans;
         for(auto a : st){
            ans.push_back(a);
         }

         return ans;
    }
};
