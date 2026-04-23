class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int i=0;
        int n = heights.size();
        int j=n-1;
        while(i<=j){
            int width = (j-i);
            int currArea = width * min(heights[i], heights[j]);
            if(currArea > maxArea){
                maxArea = currArea;
            }
            if(min(heights[i], heights[j]) == heights[i]){
                i++;
            } else{
                j--;
            }
        }
        return maxArea;
    }
};
