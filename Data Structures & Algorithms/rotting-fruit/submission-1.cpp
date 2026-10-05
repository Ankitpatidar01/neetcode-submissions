class Solution {
public:
     int X[4] = {1 , 0 , -1 , 0};
    int Y[4] = {0 , -1 , 0 , 1};

    int solve(vector<vector<int>>& grid , int m , int n){

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dis(m , vector<int>(n , 0));

        int fresh = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    pq.push({0 , {i , j}});
                    dis[i][j] = 0;
                }

                if(grid[i][j] == 1){
                   fresh++;
                }
            }
        }

        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();

            int x = a.second.first;
            int y = a.second.second;

            for(int k = 0 ; k < 4 ; k++){
                    int newx = x + X[k];
                    int newy = y + Y[k];

                    if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1){
                        grid[newx][newy] = 2;
                        fresh--;
                        dis[newx][newy] = dis[x][y] + 1;

                        if(fresh == 0) return dis[newx][newy];
                        pq.push({dis[newx][newy] , {newx , newy}});
                    }
                }


        }

        if(fresh == 0) return 0;

        return -1;

         
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(grid , m , n);
    }
};
