/*
	Task	: Bipartite_Check
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Visualgo: https://visualgo.net/en/dfsbfs
	Created	: 06 May 2021 [14:04]
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

const int N = 100010;
vector<int > g[N];
int col[N];
bool bipartite_check(int u,int c){
	if(col[u]){
		if(col[u] == c)	return true;
		else			return false;
	}
	col[u] = c;
	for(auto x:g[u]){
		if(!bipartite_check(x,3-c))
			return false;
	}
	return true;
}
//call function with bipartite_check(1,1) = start at node 1 with color 1