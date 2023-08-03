//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int Optimised(string S1, string S2, int n, int m){
        
       vector<int>dp(m+1,0);
       
        int mx=-1e9;
       
        for(int i=1;i<=n;++i){
             vector<int>curr(m+1,0);
            
            for(int j=1;j<=m;++j){
                if(S1[i-1]==S2[j-1]){
                    curr[j]=1+dp[j-1];
                }else
                curr[j]=0;
                mx=max(mx,curr[j]);
            }
            dp=curr;
        }
        return mx;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //         int mx=-1e9;
        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=m;++j){
        //         if(S1[i-1]==S2[j-1]){
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }else
        //         dp[i][j]=0;
        //      mx=max(mx,dp[i][j]);
        //     }
        // }
        // // TO UNDERSTAND SEE THIS 
        // for(auto in:dp){
        //     for(auto ele:in){
        //         cout<<ele<<" ";
        //     }cout<<endl;
        // }

        return Optimised(S1, S2,n, m);
        

    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends