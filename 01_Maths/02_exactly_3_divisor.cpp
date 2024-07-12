// https://geeksforgeeks.org/batch/dsa-4/track/DSASP-Mathematics/problem/exactly-3-divisors
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool isPrime(int n)
    {
        int i;
        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    int exactly3Divisors(int N)
    {
        int count=0,i,j;
        if(N<4)
        {
            return 0;
        }
        for(i=2;i<=sqrt(N);i++)
        {
            if(isPrime(i))
            {
                count++;
            }
        }
       
        return count;
    }
};

//{ Driver Code Starts.


int main()
 {
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
}
