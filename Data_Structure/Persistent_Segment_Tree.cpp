/*
	Task		: _Persistent_Segment_Tree
	Author		: Phumipat C. [MAGCARI]
	School		: RYW
	Language	: C++
	Explanation	: https://www.geeksforgeeks.org/persistent-segment-tree-set-1-introduction/
	Created		: 07 May 2021 [22:11]
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
struct A{
	int v;
	A *l,*r;
};
A tree[4*N];
A* ver[N];
int id;
A* build(int l,int r){
	int now = ++id;
	if(l == r)	return &tree[now];
	int mid = (l+r)/2;
	tree[now] = {0,build(l,mid),build(mid+1,r)};
	return &tree[now];
}
A* upd(int l,int r,A* origin,int idx,int v){
	int now = ++id;
	tree[now] = *origin;
	if(l == r){
		tree[now].v = v;
		return &tree[now];
	}
	int mid = (l+r)/2;
	if(idx<=mid)	tree[now].l = upd(l,mid,origin->l,idx,v);
	else			tree[now].r = upd(mid+1,r,origin->r,idx,v);
	tree[now].v = tree[now].l->v + tree[now].r->v;
	return &tree[now];
}
int read(int l,int r,A* lo,A* ro,int ll,int rr){
	if(ll>r || r<ll)	return 0;
	if(ll<=l && r<=rr)	return ro->v - lo->v;
	int mid = (l+r)/2;
	return read(l,mid,lo->l,ro->l,ll,rr) + read(mid+1,r,lo->r,ro->r,ll,rr);
}
int main(){
	int n,num;
	cin >> n;
	ver[0] = build(1,n);
	for(int i=1;i<=n;i++){
		cin >> num;
		ver[i] = upd(1,n,ver[i-1],num,1);
	}
	return 0;
}