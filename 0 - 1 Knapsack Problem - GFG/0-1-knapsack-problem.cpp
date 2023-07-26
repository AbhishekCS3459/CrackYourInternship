//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[1005][1005];
    int solve(int idx,int W, int wt[], int val[]){
        if(idx==0){
            //if the current item wt is less that W
            if(wt[0]<=W)return val[0];
            return 0;
        }
        if(dp[idx][W]!=-1)return dp[idx][W];
        
        // either we can pick or no pick
        int nopick=solve(idx-1,W,wt,val);
        
        int pick=INT_MIN;
        
        if(W-wt[idx]>=0){
            pick=solve(idx-1,W-wt[idx],wt,val)+val[idx];
        }
        return dp[idx][W]= max(pick,nopick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof(dp));
       
       return solve(n-1,W,wt,val);
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