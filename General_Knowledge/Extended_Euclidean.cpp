/*
	Task		: Extended_Euclidean
	Author		: Phumipat C. [MAGCARI]
	School		: RYW
	Language	: C++
	Explanation	:
	Created		: 08 May 2021 [13:20]
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

void extended_euclidean(int a,int b,int *x,int *y){
	if(b==0){
		*x=1;
		*y=0;
		return ;
	}
	int u,v;
	extended_euclidean(b,a%b,&u,&v);
	*x=v;
	*y=u-v*(a/b);
}