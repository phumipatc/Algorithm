/*
	Task	: Lazy_Segment_Tree
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [12:18]
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
LL tree[N*4],lazy[N+10];
void upd_range(int l,int r,int now,int ll,int rr,int v){
	if(r<ll || l>rr)	return ;
	if(ll<=l && r<=rr){
		tree[now]+=v;
		if(l!=r)	lazy[now*2]+=v,lazy[now*2+1]+=v;
		return ;
	}
	int mid = (l+r)/2;
	upd_range(l,mid,now*2,ll,rr,v),upd_range(mid+1,r,now*2+1,ll,rr,v);
	tree[now] = tree[now*2] + tree[now*2+1];
}
LL read_point(int l,int r,int now,int idx){
	if(lazy[now]){
		tree[now]+=lazy[now];
		if(l!=r)	lazy[now*2]+=lazy[now],lazy[now*2+1]+=lazy[now];
		lazy[now] = 0;
	}
	if(l == r)	return tree[now];
	int mid = (l+r)/2;
	if(idx<=mid)	return read_point(l,mid,now*2,idx);
	else			return read_point(mid+1,r,now*2+1,idx);
}
LL read_range(int l,int r,int now,int ll,int rr){
	if(r<ll || l>rr)	return 0;
	if(lazy[now]){
		tree[now]+=lazy[now];
		if(l!=r)	lazy[now*2]+=lazy[now],lazy[now*2+1]+=lazy[now];
		lazy[now] = 0;
	}
	if(ll<=l && r<=rr)	return tree[now];
	int mid = (l+r)/2;
	return read_range(l,mid,now*2,ll,rr) + read_range(mid+1,r,now*2+1,ll,rr);
}
// Function Calling
// upd_range(1,N,1,ll,rr,v);
// read_point(1,N,1,idx);
// read_range(1,N,1,ll,rr);