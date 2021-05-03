/*
	Task	: Kosaraju
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [22:23]
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
vector<int > g[N],rg[N];
int comp[N];
bool mark[N];
stack<int > st;
void dfs(int u){
	mark[u] = true;
	for(auto x:g[u]){
		if(mark[x])	continue;
		dfs(x);
	}
	st.push(u);
}
void dfs2(int u,int id){
	comp[u] = id;
	mark[u] = true;
	for(auto x:rg[u]){
		if(mark[x])	continue;
		dfs2(x,id);
	}
}
int main(){
	int n,m,u,v;
	cin >> n >> m;
	while(m--){
		cin >> u >> v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(mark[i])	continue;
		dfs(i);
	}
	memset(mark,0,sizeof mark);
	int id = 0;
	while(!st.empty()){
		int now = st.top();
		st.pop();
		id++;
		if(mark[now])	continue;
		dfs2(now,id);
	}
	return 0;
}