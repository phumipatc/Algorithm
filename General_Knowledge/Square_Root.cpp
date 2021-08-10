/*
	Task		: Approximate Square Root
	Author		: Borworntat D. [Hydrolyzed~]
	School		: RYW
	Language	: C++
	Explanation	:
	Created		: 10 Aug 2021 [23:33]
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

LL square_root(LL n){
	LL l, r;
	l = 1, r = n;
	while(l <= r){
		LL mid = (l + r) / 2;
		if(mid * mid == n){
			return mid;
		}
		if(mid <= n / mid){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return l - 1;
}
