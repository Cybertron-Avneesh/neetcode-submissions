class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int absNum = abs(nums[i]);
            if(nums[absNum] < 0){
                return absNum;
            } else{
                nums[absNum] *= -1;
            }
        }
        return -1;
    }
};
