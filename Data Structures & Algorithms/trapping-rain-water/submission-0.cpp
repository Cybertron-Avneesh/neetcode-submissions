class Solution {
public:
    int trap(vector<int>& height) {
        // use prefix and suffix arrays to initialise with max height on left and right
        // now iterate over the array and see if (min(left[i], right[i]) - height[i]) > 0
        // if yes: add to answer, else: skip
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], height[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i+1]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int tmp = min(left[i], right[i]) - height[i];
            if(tmp>0){
                ans += tmp;
            }
        }
        return ans;
    }
};
