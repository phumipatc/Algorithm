/*
	Task		: Disjoined Set Union
	Author		: Borworntat D. [Hydrolyzed~]
	School		: RYW
	Language	: C++
	Created		: 01 Oct 2021 [13:07]
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

const int N = 10010;

int parent[N];

int find_root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

void merge(int u, int v){
	int ru = find_root(ru), rv = find_root(rv);
	parent[ru] = rv; // change parent of U to parent of V
	return ;
}

// Must be called once
void init(){
	for(int i=1; i<=N; ++i){
		parent[i] = i;
	}
	return ;
}
