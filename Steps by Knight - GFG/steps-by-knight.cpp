//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int dx[8]={-2,-2,1,1,2,2,-1, -1};
int dy[8]={-1,1,-2,2,1,-1, 2, -2};
// possible moves for knight for i,j it will be  [(i+2)(j+1)or (i+2)(j-1)] or [(i-2)(j+1) or (i-2)(j+1)] or
// [(i+1,j+2) or i-1,j+2] or [(i-1)(j-2)or (i+1)(j+2)]
// or vice versa will be also true
	 // [(i+2)(j+1) or (i+2)(j-1)] or [(i-2)(j+1) or (i-2)(j-1)] or
//   [(i+1,j+2) or ( i-1)(j+2)] or [(i-1)(j-2)or (i+1)(j-2)]

	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
       int destx=TargetPos[0],desty=TargetPos[1];
         int srcx=KnightPos[0],srcy=KnightPos[1];
         queue<pair<pair<int,int>,int>>q;
         q.push({{srcx,srcy},0});
         vector<vector<int>>vis(N+1,vector<int>(N+1,0));
         vis[srcx][srcy]=1;
         
         while(!q.empty()){
             int x=q.front().first.first;
             int y=q.front().first.second;
             int dist=q.front().second;
             q.pop();
             if(x==destx&&y==desty)return dist;
             for(int i=0;i<8;++i ){
                 int nx=x+dx[i];
                 int ny=y+dy[i];
                 if(nx>=0&&nx<=N&&ny>=0&&ny<=N&&vis[nx][ny]==0){
                     vis[nx][ny]=1;
                     q.push({{nx,ny},dist+1});
                 }
             }
         }
     return -1;

	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends