class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>>v;
        int i = 0;
        for( ; i < intervals.size() ; i++){
            auto curr = intervals[i];
            
            if(curr[1] < newInterval[0]){
                v.push_back(curr);
            }else{
                break;
            }
               
        }

         while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
                    newInterval[0] = min(newInterval[0] , intervals[i][0]);
                   newInterval[1] = max(newInterval[1] , intervals[i][1]);
                   i++;
                }
               
                v.push_back(newInterval);
        
            while(i < intervals.size()){
                v.push_back(intervals[i]);
                i++;
            }   

            return v;    
    }
};
