class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        if(n<0){return 1.0/myPow(x, abs(n));}
        else{
            double powXnby2 = pow(x, n/2);
            if(n%2==1){
                return powXnby2*powXnby2*x;
            } else{
                return powXnby2*powXnby2;
            }
        }
    }
};
