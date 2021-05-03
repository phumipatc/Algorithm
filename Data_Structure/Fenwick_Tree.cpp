/*
	Task	: Fenwick_Tree
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [12:04]
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

const int N = 100000;
LL tree[N+10];
void upd(int idx,int v){
	for(;idx<=N;idx+=idx&=idx)
		tree[idx]+=v;
}
LL read(int idx,LL sum=0){
	for(;idx;idx-=idx&-idx)
		sum+=tree[idx];
	return sum;
}