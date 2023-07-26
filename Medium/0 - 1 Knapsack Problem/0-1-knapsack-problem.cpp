//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[1005][1005];
    int solve(int W, int wt[], int val[],int n){
        
        for(int wti=wt[0];wti<=W;++wti){
            dp[0][wti]=val[0];
        }
        
        for(int idx=1;idx<n;++idx){
            for(int tar=0;tar<=W;++tar){
                // either we can pick or no pick
                int nopick=dp[idx-1][tar];
                
                int pick=INT_MIN;
                
                if(tar-wt[idx]>=0){
                    pick=dp[idx-1][tar-wt[idx]]+val[idx];
                }
                dp[idx][tar]= max(pick,nopick);
            }
        }
        return dp[n-1][W];

    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,0,sizeof(dp));
       
       return solve(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends