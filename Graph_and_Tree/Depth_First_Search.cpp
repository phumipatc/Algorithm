/*
	Task	: Depth First Search
	Author	: Borworntat D. [Hydrolyzed~]
	School	: RYW
	Language: C++
	Created	: 10 Aug 2021 [12:30]
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
bool visited[N];

// call dfs_rec(source, 0)
void dfs_rec(int u, int p){
	cout << u << " ";
	visited[u] = true;
	for(auto x: adj[u]){
		if(!visited[x]){
			dfs_rec(x, u);
		}
	}
}

// call dfs_stack(source)
void dfs_stack(int source){
	memset(visited, false, sizeof visited);
	stack<int> st;
	st.push(source);
	while(!st.empty()){
		int now = st.top();
		st.pop();
		cout << now << " ";
		for(auto x: adj[now]){
			if(!visited[x]){
				visited[x] = true;
				st.push(x);
			}
		}
	}
}
