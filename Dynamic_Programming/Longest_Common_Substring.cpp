/*
	Task	: Longest_Common_Substring
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [12:57]
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
char a[N],b[N];
int LCS(){
	int n = strlen(a+1),m = strlen(b+1);
	int maxx = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i] == b[j])
				dp[i][j] = dp[i-1][j-1]+1;
			maxx = max(maxx,dp[i][j]);
		}
	}
	return maxx;
}
int main(){
	cin >> a+1 >> b+1;
	cout << LCS();
	return 0;
}