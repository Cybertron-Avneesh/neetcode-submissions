class Solution {
public:
    vector<int> idxToij(int idx, int rows, int cols){
        return {idx/cols, idx%cols};
    }
    int ijToIdx(int i, int j, int rows, int cols){
        return i*cols+j;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lo = 0;
        int hi = rows*cols - 1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            vector<int> idx = idxToij(mid, rows, cols);
            if(matrix[idx[0]][idx[1]] == target) return true;
            if(matrix[idx[0]][idx[1]] < target) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return false;
    }
};
