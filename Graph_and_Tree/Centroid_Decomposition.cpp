/*
	Task		: Centroid_Decomposition
	Author		: Phumipat C. [MAGCARI]
	School		: RYW
	Language	: C++
	Explanation	: https://www.geeksforgeeks.org/centroid-decomposition-of-tree/
	Explanation	: https://codeforces.com/blog/entry/81661
	Created		: 24 May 2021 [19:41]
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

const int N = 1e5+10;
vector<int > g[N];
int p[N],vis[N],sz[N];
int find_size(int u,int pa = 0){
	if(vis[u])	return 0;
	sz[u] = 1;
	for(auto x:g[u]){
		if(x == pa)	continue;
		sz[u]+=find_size(x,u);
	}
	return sz[u];
}
int find_centroid(int u,int pa,int n){
	for(auto x:g[u]){
		if(x == pa)		continue;
		if(vis[x])		continue;
		if(sz[x]<=n/2)	continue;
		return find_centroid(x,u,n);
	}
	return u;
}
int init_centroid(int u,int pa){
	find_size(u);
	int c = find_centroid(u,pa,sz[u]);
	vis[c] = 1;
	p[c] = pa;
	for(auto x:g[c]){
		if(vis[x])	continue;
		init_centroid(x,c);
	}
}
// init_centroid(1,0)