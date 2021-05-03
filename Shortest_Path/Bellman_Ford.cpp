/*
	Task	: Bellman_Ford
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [14:57]
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
struct A{
	int u,v,w;
};
LL dis[N];
// Bellman Ford can be used to detect "Negative Weight Cycle"
LL bellman_ford(int n,int st,int en,vector<A > edges){
	dis[st] = 0;
	for(int i=1;i<n;i++){
		for(auto x:edges){
			if(dis[x.u] + x.w<dis[x.v])	dis[x.v] = dis[x.u] + x.w;
			if(dis[x.v] + x.w<dis[x.u])	dis[x.u] = dis[x.v] + x.w;
		}
	}
	for(auto x:edges){
		if(dis[x.u] + x.w<dis[x.v] || dis[x.v] + x.w<dis[x.u])
			return -1;	// Negative weight cycle detected
	}
	return dis[en];
}
int main(){
	int n,m;
	vector<A > edges;
	cin >> n >> m;
	fill(dis,dis+n+1,1e18);
	edges.resize(m);
	for(int i=0;i<m;i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	cout << bellman_ford(n,1,n,edges);
	return 0;
}