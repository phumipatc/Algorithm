/*
	Task		: _Articulation_Points_and_Bridges
	Author		: Phumipat C. [MAGCARI]
	School		: RYW
	Language	: C++
	Explanation	: http://www.cs.kent.edu/~aleitert/iga/slides/04ArtPointsBridges.pdf
	visualgo	: https://visualgo.net/en/dfsbfs
	Created		: 08 May 2021 [22:45]
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
vector<int > g[N],points;
vector<PII > bridges;
int idx[N],low[N];
int id,root = 1;
void dfs(int u,int p){
	idx[u] = low[u] = ++id;
	for(auto x:g[u]){
		if(x == p)	continue;
		if(!idx[x])			dfs(x,u),low[u] = min(low[u],low[x]);
		else				low[u] = min(low[u],idx[x]);
		if(u != root && low[x]>=idx[u])	points.push_back(u);
		if(low[x]>idx[u])				bridges.push_back({u,x});
	}
}