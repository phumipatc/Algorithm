/*
	Task		: Dijkstra
	Author		: Phumipat C. [MAGCARI]
	School		: RYW
	Language	: C++
	Explanation	: 
	Created		: 09 August 2021 [22:13]
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

const int N = 10010;
struct A{
	int current_node,total_distance;
	A(int n,int d):current_node(n),total_distance(d){}
	bool operator < (const A&o) const{
		return total_distance>o.total_distance;
	}
};
int dis[N];
vector<pair<int ,int > > g[N];
int dijkstra(int source,int destination){
	priority_queue<A > heap;
	fill(dis,dis+N,2e9);
	dis[source] = 0;
	heap.push({source,0});
	while(!heap.empty()){
		auto now = heap.top();
		heap.pop();
		for(auto x:g[now.current_node]){
			if(dis[x.first]<=now.total_distance+x.second)	continue;
			dis[x.first] = now.total_distance + x.second;
			heap.push({x.first,dis[x.first]});
		}
	}
	return dis[destination];
}
int main(){
	int n,m,source,destination;
	cin >> n >> m >> source >> destination;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
	}
	cout << dijkstra(source,destination);
	return 0;
}