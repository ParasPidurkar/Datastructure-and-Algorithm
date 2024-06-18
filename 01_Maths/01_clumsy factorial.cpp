//https://leetcode.com/problems/clumsy-factorial/
class Solution {
public:
    int clumsy(int n) {
        int    result=0,temp=0,op=-1;
        temp=n;
        n-- ;op++;
        while(n>0){
            if(op ==0){
                temp*=n;
            }
            if(op ==1){
                temp/=n;
            }
            if(op ==2){
                temp+=n;}
             if(op ==3){   
                op  =-1;
                result+=temp;
                temp = -n;
            }
            op++  ;
            n--;
        }
        return temp+result;

        
    }
};