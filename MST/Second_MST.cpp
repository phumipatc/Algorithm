/*
	Task		: Second_MST
	Author		: Phumipat C. [MAGCARI]
	Language	: C++
	Explanation	: 
	Created		: 09 December 2021 [22:16]
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
struct A{
	int u,v,w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
vector<PII > g[N];

int LCA[N][20],weight[N][20],lv[N];

int p[N];
int fr(int n){
	return (p[n] == n)?n:(p[n] = fr(p[n]));
}

void init_LCA(int u,int pa,int w,int lvl = 1){
	LCA[u][0] = pa;
	weight[u][0] = w;
	lv[u] = lvl;
	for(int i=1;i<=18;i++){
		LCA[u][i] = LCA[LCA[u][i-1]][i-1];
		weight[u][i] = max(weight[u][i-1],weight[LCA[u][i-1]][i-1]);
	}
	for(auto x:g[u]){
		if(x.first == pa)	continue;
		init_LCA(x.first,u,x.second,lvl+1);
	}
}

PII find_LCA_weight(int u,int v){
	if(u == v)	return {u,0};

	int max_weight = 0;
	
	if(lv[u] < lv[v])	swap(u,v);
	
	// lower level of u
	for(int i=18;i>=0;i--){
		if(lv[LCA[u][i]]<lv[v])	continue;
		max_weight = max(max_weight,weight[u][i]);
		u = LCA[u][i];
	}

	if(u == v)

	// find ancestor
	for(int i=18;i>=0;i--){
		if(LCA[u][i] == LCA[v][i])	continue;
		max_weight = max({max_weight,weight[u][i],weight[v][i]});
		u = LCA[u][i],v = LCA[v][i];
	}

	// last step up
	max_weight = max({max_weight,weight[u][0],weight[v][0]});
	u = LCA[u][0],v = LCA[v][0];
	return {u,max_weight};
}

pair<int ,vector<A > > init_MST(vector<A > edges){
	vector<A > unused;
	
	iota(p,p+N,0);
	sort(all(edges));
	
	int sum = 0;
	for(auto x:edges){
		int ru = fr(x.u),rv = fr(x.v);
		if(ru == rv){
			unused.push_back(x);
			continue;
		}
		p[ru] = rv;
		sum+=x.w;
		g[x.u].push_back({x.v,x.w});
		g[x.v].push_back({x.u,x.w});
	}
	return {sum,unused};
}

int second_MST(vector<A > edges){
	auto temp = init_MST(edges);
	int sum = temp.first;
	vector<A > unused = temp.second;
	init_LCA(1,0,0);

	int ans = 1e9;
	for(auto x:unused){
		PII old = find_LCA_weight(x.u,x.v);
		ans = min(ans,sum - old.second + x.w);
	}
	return ans;
}