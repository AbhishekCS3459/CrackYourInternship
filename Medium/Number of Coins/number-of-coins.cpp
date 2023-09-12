//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
;
	public:
	int solve(int coins[],int tar,int idx,vector<vector<int>>&dp){
	    if(tar==0)return 0;
	    if(idx==0){
	        if(tar%coins[0]==0)return tar/coins[0];
	        return 1e8;
	    }
if(dp[idx][tar]!=-1)return dp[idx][tar];
    int not_take=solve(coins,tar,idx-1,dp);
    if(tar-coins[idx]>=0){
      int take=solve(coins,tar-coins[idx],idx,dp)+1;
        not_take=min(not_take,take);
    }
     return dp[idx][tar]= not_take;
	}

	int minCoins(int coins[], int M, int V) 
	{ 
	    // appply dp not greedy see case 2
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    int ans=solve(coins,V,M-1,dp);
	    if(ans==1e8)return -1;
	    else
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends