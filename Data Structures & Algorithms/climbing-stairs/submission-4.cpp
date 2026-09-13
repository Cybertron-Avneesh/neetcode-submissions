class Solution {
public:
    
    int climbStairs(int n) {
        if(n<=2) return n;
        int i_2 = 1;
        int i_1 = 2;
        int curr = 0;
        for(int i=3; i<=n; i++){
            curr = i_1 + i_2;
            i_2 = i_1;
            i_1 = curr;
        }    
        return curr;
    }
};
