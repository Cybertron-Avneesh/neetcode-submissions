class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int topRow = 0;
        int bottomRow = rows-1;
        int leftCol = 0;
        int rightCol = cols-1;
        while(topRow<=bottomRow && leftCol<=rightCol){
            // top row row = topRow, col: [leftCol->rightCol]
            for(int j=leftCol; j<=rightCol; j++){
                ans.push_back(matrix[topRow][j]);
            }
            topRow++;
            // right col row: [topRow, bottomRow], col: [rightCol]
            for(int i=topRow; i<=bottomRow; i++){
                ans.push_back(matrix[i][rightCol]);
            }
            rightCol--;
            // bottom row in reverse row: bottomRow, col: [rightCol, leftCol]
            if(topRow<=bottomRow){ // mendatory checks needed
                for(int j=rightCol; j>=leftCol; j--){
                    ans.push_back(matrix[bottomRow][j]);
                }
                bottomRow--;
            }
            // left col in reverse row: [bottomRow, topRow] col: leftCol
            if(leftCol<=rightCol){ // mendatory checks needed
                for(int j=bottomRow; j>=topRow; j--){
                    ans.push_back(matrix[j][leftCol]);
                }
                leftCol++;
            }
        }
        return ans;
    }
};
