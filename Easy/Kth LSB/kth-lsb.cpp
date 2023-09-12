//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int KthLSB(long long int n, int k){
	    //simply do left shift 1 as many times it asked
	   // check the ith bit is set or unset
	   return (n>>(k-1))&1;
	    
	}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        int k;
        cin >> n >> k;
        Solution ob;
        
        cout << ob.KthLSB(n, k) << endl;
    }
return 0;
}


// } Driver Code Ends