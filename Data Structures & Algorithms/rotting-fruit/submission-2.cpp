class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        bool hasFruit = false;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    hasFruit = true;
                }
            }
        }
        if(q.size() == 0 && hasFruit) return -1;
        if(q.size() == 0 && !hasFruit) return 0;
        int time = 0;
        while(q.size()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                if(grid[front.first][front.second] == 2){
                    for(auto dir: dirs){
                        int I = dir[0] + front.first;
                        int J = dir[1] + front.second;
                        if(I<0 || J<0 || I>= rows || J>=cols){
                            continue;
                        }
                        if(grid[I][J] == 1){
                            grid[I][J] = 2;
                            q.push({I, J});
                        }
                    }
                }
            }
            time++;
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time-1;
    }
};
