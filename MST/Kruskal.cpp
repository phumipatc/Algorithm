/*
	Task	: Kruskal
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [11:38]
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
const int N = 100010;
struct A{
	int u,v;
	LL w;
};
int p[N];
int fr(int u){
	return (u == p[u]?u:p[u] = fr(p[u]));
}
LL kruskal(vector<A > edges){
	LL sum = 0;
	sort(all(edges));
	for(auto x:edges){
		int ru = fr(x.u),rv = fr(x.v);
		if(ru == rv)	continue;
		p[ru] = rv;
		sum+=x.w;
	}
	return sum;
}
int main(){
	int n,m,u,v,w;
	vector<A > edges;
	cin >> n >> m;
	iota(p,p+n+1,0);
	while(m--){
		cin >> u >> v >> w;
		edges.emplace_back(u,v,w);
	}
	cout << kruskal(edges);
	return 0;
}