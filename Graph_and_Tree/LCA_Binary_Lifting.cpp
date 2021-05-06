/*
	Task	: LCA_Binary_Lifting
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 06 May 2021 [14:54]
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
const int logN = 20;
vector<int > g[N];
int LCA[N][logN],lv[N];
void dfs(int u,int p,int lvl){
	LCA[u][0] = p;
	lv[u] = lvl;
	for(int i=1;i<=18;i++)
		LCA[u][i] = LCA[LCA[u][i-1]][i-1];
	for(auto x:g[u]){
		if(x == p)	continue;
		dfs(x,u,lvl+1);
	}
}
int find_LCA(int u,int v){
	if(lv[u]<lv[v])	swap(u,v);
	for(int i=18;i>=0;i--){
		if(lv[LCA[u][i]]<lv[v])	continue;
		u = LCA[u][i];
	}
	if(u == v)	return u;

	for(int i=18;i>=0;i--){
		if(LCA[u][i] == LCA[v][i])	continue;
		u = LCA[u][i],v = LCA[v][i];
	}
	return LCA[u][0];
}