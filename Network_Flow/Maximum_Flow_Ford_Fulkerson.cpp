/*
	Task		: Maximum_Flow_Ford_Fulkerson
	Author		: Phumipat C. [MAGCARI]
	School		: RYW
	Language	: C++
	Explanation	: https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm
	Visualgo
	Created		: 09 May 2021 [13:18]
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

const int N = 1010;
vector<int > g[N];
queue<int > que;
int res[N][N],dis[N],p[N],s,t;
int augment(int u,int now){
    if(u==s)        return now;
    if(p[u]==-1)    return 0;
    int cap=augment(p[u],min(now,res[p[u]][u]));
    res[p[u]][u]-=cap;
    res[u][p[u]]+=cap;
    return cap;
}
int max_flow(int n){
	int flow = 1e9,maxx = 0;
    while(flow){
        memset(p,-1,sizeof p);
		fill(dis+1,dis+n+1,1e9);
        dis[s] = 0;
        que.push(s);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            if(u == t)	break;
            for(auto v:g[u]){
                if(res[u][v]==0)    continue;
                if(dis[v]>dis[u]+1){
                    dis[v] = dis[u]+1;
                    p[v] = u;
                    que.push(v);
                }
            }
        }
        flow = augment(t,1e9);
        maxx+=flow;
    }
    return maxx;
}
