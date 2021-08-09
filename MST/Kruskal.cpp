/*
	Task	: Kruskal
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	visualgo: https://visualgo.net/en/mst
	Created	: 03 May 2021 [11:38]
*/
#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;

const int N = 100010;
struct A{
	int u,v;
	LL w;
	A(int u,int v,LL w):u(u),v(v),w(w){}
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
int p[N];
int fr(int u){
	if(p[u] == u)	return u;
	else			return p[u] = fr(p[u]);
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