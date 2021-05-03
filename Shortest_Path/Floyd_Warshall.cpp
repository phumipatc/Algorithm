/*
	Task	: Floyd_Warshall
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [15:07]
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

const int N = 1010;
LL dis[N][N];
// Floyd-Warshall is All-pairs Shortest Path
void floyd_warshall(int n){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
}
int main(){
	int n,m,u,v;
	LL w;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j] = 1e18;
	while(m--){
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] = min({dis[u][v],dis[v][u],w});
	}
	floyd_warshall(n);
	return 0;
}