//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
//   int get_maxvalue(int idx,int target,int value[],vector<vector<int>>&dp){
//       // base case 
      
//       if(idx==0){
//           return value[0]*target;
//       }
//     // ----- > or ---> both are same here we are not stopping at idx at 0
//     // if(target==0|| idx<0)return 0;
//          // take or no take case
//       if(dp[idx][target]!=-1)return dp[idx][target];
//       int take=0;
//       if(target-(idx+1)>=0){
//           take=get_maxvalue(idx,target-(idx+1),value,dp)+value[idx];
//       }
//       int notake=get_maxvalue(idx-1,target,value,dp);
//       return dp[idx][target]=max(take,notake);
//   }
  int get_maxvalueTabulated(int target,int price[]){
      // base case 
      int n=target;
    //   if(idx==0){
    //       return value[0]*target;
    //   }
    // ----- > or ---> both are same here we are not stopping at idx at 0
    // if(target==0|| idx<0)return 0;
    vector<vector<int>>dp(n,vector<int>(n+1,0));
     for(int tar=0;tar<=target;++tar){
         dp[0][tar]=price[0]*tar;
     }
     
     for(int idx=1;idx<n;++idx){
         for(int tar=0;tar<=target;++tar){
               // take or no take case
              int take=0;
              if(tar-(idx+1)>=0){
                  take=dp[idx][tar-(idx+1)]+price[idx];
              }
               int notake=dp[idx-1][tar];
               
               dp[idx][tar]=max(take,notake);
        }
      }
      return dp[n-1][n];
     
  }
    int cutRod(int price[], int n) {
        //code here
        return get_maxvalueTabulated(n,price);
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