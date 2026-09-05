class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        reverse(digits.begin(), digits.end());
        for(int i=0; i<digits.size(); i++){
            int tmp = digits[i]+carry;
            digits[i] = tmp%10;
            carry = tmp/10;
            if(carry == 0) break;
        }
        if(carry != 0){
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
