//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int get_maxvalue(int idx,int target,int value[],vector<vector<int>>&dp){
      // base case 
      if(target==0){
          return 0;
      }
      
      if(idx<0){
          return 0;
      }

      // take or no take case
      if(dp[idx][target]!=-1)return dp[idx][target];
      int take=0;
      if(target-(idx+1)>=0){
          take=get_maxvalue(idx,target-(idx+1),value,dp)+value[idx];
      }
       int notake=get_maxvalue(idx-1,target,value,dp);
      return dp[idx][target]=max(take,notake);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        return get_maxvalue(n-1,n,price,dp);
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