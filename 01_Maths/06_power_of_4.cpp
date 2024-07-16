//https://leetcode.com/problems/power-of-four/submissions/1323279839/


class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
        return false;
        while(n%4==0)
        {
            n=n/4;
        }
        return n==1;
        
    }
};
