/*
	Task	: Catalan_Number
	Author	: Borworntat D. [Hydrolyzed~]
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

const int N = 10010;
int dp[N];

int catalan_topdown(int n){
	if(dp[n] != -1){
		return dp[n];
	}
	if(n <= 1){
		return dp[n] = 1;
	}
	int ret = 0;
	for(int i=0; i<n; ++i){
		ret += catalan_topdown(i) * catalan_topdown(n - i - 1);
	}
	return dp[n] = ret;
}

int catalan_bottomup(int n){
	dp[0] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=0; j<i; ++j){
			dp[i] += (dp[j] * dp[i - j - 1]);
		}
	}
	return dp[n];
}

void initial_for_topdown(){
	memset(dp, -1, sizeof dp);
}