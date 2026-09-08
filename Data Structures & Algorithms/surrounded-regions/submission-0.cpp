class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if((i==0 || i==rows-1 || j==0 || j==cols-1) && board[i][j] == 'O'){
                    board[i][j] = '#';
                    q.push({i, j});
                }
            }
        }
        while(q.size()>0){
            pair<int,int> front = q.front();
            q.pop();
            cout<<front.first<< " "<<front.second<<endl; 
            for(auto dir: dirs){
                int i=front.first +dir[0];
                int j=front.second + dir[1];
                if(i<0 || i>=rows || j<0 || j>=cols){
                    continue;
                }
                if(board[i][j] == 'O'){
                    board[i][j] = '#';
                    q.push({i, j});
                }
            }
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
