/*
	Task	: Mod_of_Power
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [15:15]
*/
#include<bits/stdc++.h>
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
LL mod_of_power(LL a,LL b,LL c = MOD){	// pow(a,b)%c
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = mod_of_power(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}