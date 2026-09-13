class Solution {
public:
    int f(int i, vector<int> &mem){
        if(i<=2) return i;
        if(mem[i] != 0){
            return mem[i];
        }
        int ways = f(i-1, mem) + f(i-2, mem);
        mem[i] = ways;
        return mem[i];
    }
    int climbStairs(int n) {
        vector<int> mem(n+1, 0);
        return f(n, mem);
    }
};
