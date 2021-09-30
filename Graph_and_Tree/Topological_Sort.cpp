/*
	Task	: Topological Sort (Depth First Search)
	Author	: Borworntat D. [Hydrolyzed~]
	School	: RYW
	Language: C++
	Created	: 30 Sep 2021 [10:54]
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
vector<int> adj[N];
int in[N];
bool visited[N];

void dfs(int u){
	if(visited[u]){
		return ;
	}
	visited[u] = true;
	cout << u << " ";
	for(auto x:  adj[u]){
		if(--in[x] == 0){
			dfs(x);
		}
	}
}

int main(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		in[v]++;
	}
	for(int i=1; i<=n; ++i){
		if(in[i] == 0){
			dfs(i);
		}
	}
	return 0;
}
