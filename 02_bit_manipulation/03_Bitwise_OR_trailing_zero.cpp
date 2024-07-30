//https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/submissions/1338738546/

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count =0;
        for (size_t i = 0; i < nums.size(); ++i) {
        if( nums[i]%2 ==0)
        {
            count++;
        }   
    }
    if (count >1)
        return true;
        else 
        return false;
        
    }
};
