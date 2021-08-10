/*
	Task		: Fermat's Little Theorem
	Author		: Borworntat D. [Hydrolyzed~]
	School		: RYW
	Language	: C++
	Explanation	:
	Created		: 10 Aug 2021 [11:40]
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

LL mod_of_power(LL a, LL b, LL c){
	if(b == 1){
		return a % c;
	}
	LL tmp = mod_of_power(a, b/2, c);
	if(b % 2 == 0){
		return ((tmp % c) * (tmp % c)) %c;
	}
	return ((tmp % c) * (tmp % c) * (a % c)) % c;
}

// (a / b) mod c
LL fermat_litte_theorem(LL a, LL b, LL c){
	LL inverse_b = mod_of_power(b, c-2, c);
	LL ret = (inverse_b * (a % c))%c;
	return ret;
}