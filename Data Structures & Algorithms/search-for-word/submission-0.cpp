class Solution {
public:
    int X[4] = {1 , 0 , -1 , 0};
    int Y[4] = {0, -1 , 0 , 1};
    bool solve(vector<vector<char>>& board, string word , int i , int j , int index ,vector<vector<int>>& vis , int n , int m){

    if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || board[i][j] != word[index]) return false;

    if(index == word.length() - 1) return true;

    vis[i][j] = 1;

       for(int k = 0 ; k < 4 ; k++){
          int newx = i + X[k];
          int newy = j + Y[k];

          bool ans = solve(board , word , newx , newy , index + 1 , vis, n , m);
          if(ans == true) return true;
       }

       vis[i][j] = 0;

       return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(solve(board , word , i , j , 0 , vis , n , m)) return true;
            }
        }
        return false;
    }
};