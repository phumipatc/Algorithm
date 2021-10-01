/*
	Task		: Fenwick_Tree 2D
	Author		: Borworntat D. [Hydrolyzed~]
	School		: RYW
	Language	: C++
	Created		: 01 Oct 2021 [08:51]
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
LL tree[N][N];
void upd(int idxi, int idxj,int v){
	for(; idxi<=N-10; idxi+=idxi&-idxi){
		int now = idxj;
		for(; now<=N-10; now+=now&-now){
			tree[idxi][now] += v;
		}
	}
}
LL read(int idxi, int idxj, LL sum=0){
	for(;idxi;idxi-=idxi&-idxi){
		int now = idxj;
		for(; now; now-=now&-now){
			sum += tree[idxi][now];
		}
	}
	return sum;
}
