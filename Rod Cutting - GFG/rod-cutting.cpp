//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int get_maxvalue(int target,int value[],vector<vector<int>>&dp){
    int n=target;
    //   // base case 
    //   if(idx==0){
    //       return target*value[0];
    //   }
    
    for(int tar=0;tar<=target;++tar){
        dp[0][tar]=tar*value[0];
    }
   
  for(int idx=1;idx<n;++idx){
      for(int tar=0;tar<=target;++tar){
        int take=-1e9;
        int weight=idx+1;
          if(tar-weight>=0){
              take=dp[idx][tar-weight]+value[idx];
          }
      int notake=dp[idx-1][tar];
        dp[idx][tar]=max(take,notake);
      }
  }
   return dp[n-1][n];
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        
        return get_maxvalue(n,price,dp);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends