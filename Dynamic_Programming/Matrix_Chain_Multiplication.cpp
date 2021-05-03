/*
	Task	: Matrix_Chain
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [13:32]
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};

const int N = 1010;
int dp[N][N];
//Top Down Approach
int mcm_topdown(int l,int r){
	if(l == r)			return 0;
	if(dp[l][r]!=-1)	return dp[l][r];
	int ret = 1e9;
	for(int k=l;k<r;k++)
		ret = min(ret,mcm_topdown(l,k)+mcm_topdown(k+1,r));	// Calculate function can be added if you need
	return dp[l][r] = ret;
}
// Bottom Up Approach
int mcm_bottomup(int n){
	for(int k=1;k<=n;k++){				// k stands for "Length"
		for(int i=1;i+k-1<=n;i++){		// i stands for "Start point" so i+k-1 is "End point"
			dp[i][i+k-1] = 1e9;
			for(int j=i;j<i+k-1;j++)	// j stands for "Divide point"
				dp[i][i+k-1] = min(dp[i][i+k-1],dp[i][j]+dp[j+1][i+k-1]);	// Calculate function can be added if you need
		}
	}
	return dp[1][n];
}
void initial_for_topdown(){
	memset(dp,-1,sizeof dp);
}