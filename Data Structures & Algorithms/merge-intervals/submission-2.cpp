class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<pair<int,int>>st;
        
        sort(intervals.begin() , intervals.end());
        for(int i = 0 ; i < intervals.size() ; i++){
            if(st.empty()){
                st.push({intervals[i][0] , intervals[i][1]});
            }else{
                int start = intervals[i][0];
                int end = intervals[i][1];
                while(!st.empty() && st.top().second >= intervals[i][0]){
                    start = min(start , st.top().first);
                    end = max(end , st.top().second);
                    st.pop();
                }

                st.push({start , end});
            }
           
        }

        vector<vector<int>>ans;

        while(!st.empty()){
            ans.push_back({st.top().first , st.top().second});
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;


    }
};
