//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
const int M=1e9+7;
  long long dfs(int rx,int ry, int m,int n,vector<vector<long long>>&grid, vector<vector<long long>>&dp){
      
      if(rx==m-1&&ry==n-1){
          return 1;
      }
      
      if(dp[rx][ry]!=-1)return dp[rx][ry];
      
     long long total=0;
     
      if(rx+1<m){
        total+=dfs(rx+1,ry,m,n,grid,dp)%M;
      }

      if(ry+1<n){
        total+=dfs(rx,ry+1,m,n,grid,dp)%M;
      }
      
    return dp[rx][ry]= total%M;
  }
    long long int numberOfPaths(int m, int n){
    vector<vector<long long>> grid(m, vector<long long>(n, 0));

    vector<vector<long long>> dp(m, vector<long long>(n, -1));
        return dfs(0,0,m,n,grid,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends