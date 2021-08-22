/*
	Task		: Maximum_Subsequence_Sum_Kadane
	Author		: Phumipat C. [MAGCARI]
	Language	: C++
	Explanation	: 
	Created		: 22 August 2021 [11:33]
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

const int N = 10010;
int num[N];
int kadane(int n){
	int sum = 0,maxx = 0;
	for(int i=1;i<=n;i++){
		sum+=num[i];
		maxx = max(maxx,sum);
		if(sum<0)	sum = 0;
	}
	return maxx;
}