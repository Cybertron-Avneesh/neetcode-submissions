class Solution {
public:
    int maxArea(vector<int>& heights) {
        // approach 1: brute force, run two loops and find all possible areas' max
        // approach 2: optimal, two pointer
        //  - have two pointers, l=0, r=n-1
        //  - area = min(h[l], h[r]) * (r - l)
        //  maxArea = max(area, maxArea);
        // now in order to move these pointers, we know tw things, that (r-l) is going to reduce by 1
        // in new window area can be greater or lesser, and we need to maximise it
        // we cant control (r-l) but we can control min(h[l], h[r])
        // hence inorder to maximise the area, we should shift the pointer of smaller height container
        // this provides with the opportunity to expect a bigger height container in next step.
        int maxArea = 0;
        int n = heights.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            int area = min(heights[l], heights[r]) * (r - l);
            maxArea = max(area, maxArea);
            if(heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
};
