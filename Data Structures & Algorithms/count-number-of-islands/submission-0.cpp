class Solution {
public:
    int X[4] = {1 , 0 , -1 , 0};
    int Y[4] = {0 , -1 , 0 , 1};

    void solve(int x , int y , vector<vector<char>>& grid , vector<vector<int>>& vis , int m , int n){
        vis[x][y] = 1;

        for(int i = 0 ; i < 4 ; i++){
            int newx = x + X[i];
            int newy = y + Y[i];

            if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == '1' && vis[newx][newy] == 0){
                solve(newx , newy , grid , vis , m , n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m , vector<int>(n , 0));
        int count = 0;
        

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){

                if(grid[i][j] == '1' && vis[i][j] == 0){
                   solve(i , j , grid , vis , m , n);
                   count++;
                }
                
            }
        }

        return count;
    }
};
