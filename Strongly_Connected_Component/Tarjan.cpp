/*
	Task	: Tarjan
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	visualgo: https://visualgo.net/en/dfsbfs
	Created	: 03 May 2021 [12:26]
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
vector<int > g[N];
int idx[N],low[N],onstack[N],comp[N];
stack<int > st;
int id,comp_num;
void dfs(int u,int p){
	idx[u] = low[u] = ++id;
	onstack[u] = 1;
	st.push(u);
	for(auto x:g[u]){
		if(x == p)	continue;
		if(!idx[x])			dfs(x,u),low[u] = min(low[u],low[x]);
		else if(onstack[x])	low[u] = min(low[u],idx[x]);
	}
	if(idx[u] == low[u]){
		++comp_num;
		while(!comp[u]){
			comp[st.top()] = comp_num;
			onstack[st.top()] = 0;
			st.pop();
		}
	}
}
//comp[i] = ID of SCC that i-node relies on