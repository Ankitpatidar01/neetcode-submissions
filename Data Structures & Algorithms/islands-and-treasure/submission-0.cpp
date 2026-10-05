class Solution {
public:
    int X[4] = {1 , 0 , -1 , 0};
    int Y[4] = {0 , -1 , 0 , 1};

    void solve(vector<vector<int>>& grid , int m , int n){

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0)
                pq.push({0 , {i , j}});
            }
        }

        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();

            int dis = a.first;
            int x = a.second.first;
            int y = a.second.second;

            for(int k = 0 ; k < 4 ; k++){
                    int newx = x + X[k];
                    int newy = y + Y[k];

                    if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] != -1 && grid[newx][newy] + 1 < grid[x][y]){
                        grid[newx][newy] = grid[x][y] + 1;
                        pq.push({grid[newx][newy] , {newx , newy}});
                    }
                }


        }

         
    }


    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        solve(grid , m , n);

        return;
       
    }
};
