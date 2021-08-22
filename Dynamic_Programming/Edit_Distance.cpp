/*
	Task		: Edit_Distance
	Author		: Phumipat C. [MAGCARI]
	Language	: C++
	Explanation	: 
	Created		: 22 August 2021 [11:37]
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};

const int N = 1010;
char a[N],b[N];
int dp[N][N];

int edit_distance(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i] == b[j])	dp[i][j] = dp[i-1][j-1];
			else				dp[i][j] = min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]}) + 1;
		}
	}
	return dp[n][m];
}