class Solution {
public:

  int X[4] = {1 , 0 , -1 , 0};
  int Y[4] = {0 , -1 , 0 , 1};
   
   bool solve(vector<vector<char>>& grid , int x , int y , int index , string& word , int m , int n , vector<vector<int>>& vis){

       if (index == word.size() - 1)
            return true;
        vis[x][y] = 1;
       
        for(int i = 0 ; i < 4 ; i++){
            int newx = x + X[i];
            int newy = y + Y[i];

            if(newx >= 0 && newx < m && newy >= 0 && newy < n && vis[newx][newy] == 0 && word[index + 1] == grid[newx][newy]){
                if(solve(grid , newx , newy , index + 1 , word , m , n , vis)){
                    return true;
                }
            }
        }

        vis[x][y] = 0;

        return false;

   }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>vis(m , vector<int>(n , 0));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0]){
                    if(solve(board , i , j , 0 , word , m , n , vis)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
