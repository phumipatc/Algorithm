/*
	Task	: Weighted_Interval_Scheduling
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [19:43]
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
struct A{
	int st,en;
	LL w;
	bool operator < (const A&o) const{
		if(en!=o.en)	return en<o.en;
		else			return st<o.st;
	}
};
A a[N];
int en[N];
LL dp[N];
int weighted_interval_scheduling(int n){
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		en[i] = a[i].en;
	for(int i=1;i<=n;i++){
		int idx = lower_bound(en+1,en+n+1,a[i].st)-en-1;	// find dp[j] that a[j].en < a[i].st
		dp[i] = max(dp[i-1],dp[idx] + a[i].w);				// we are comparing between picking i-th range or not picking it
	}
	return dp[n];
}