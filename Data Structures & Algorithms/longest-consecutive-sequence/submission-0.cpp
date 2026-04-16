class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto a: nums){
            st.insert(a);
        }
        int longest = 0;
        for(auto a: nums){
            int currLen = 1;
            if(st.find(a-1) == st.end()){
                // a is our starting number to start counting since a-1 is not present in set
                while(st.find(a+currLen) != st.end()){
                    currLen++;
                }
                longest = max(longest, currLen);
            }
        }
        return longest;
    }
};
