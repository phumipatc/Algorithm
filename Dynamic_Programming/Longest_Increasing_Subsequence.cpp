/*
	Task	: Longest_Increasing_Subsequence
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [12:43]
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

const int N = 100010;
int dp[N],a[N];
int LIS(int n){
	int maxx=0;
	for(int i=1;i<=n;i++){
		int idx = lower_bound(dp,dp+maxx,a[i])-dp;
		if(idx == maxx)	maxx++;
		dp[idx] = a[i];
	}
	return maxx;
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	cout << LIS(n);
	return 0;
}