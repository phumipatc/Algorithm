/*
	Task	: Prim
	Author	: Borworntat D. [Hydrolyzed~]
	School	: RYW
	Language: C++
	visualgo: https://visualgo.net/en/mst
	Created	: 10 Aug 2021 [11:29]
*/
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;

const int N = 100010;
struct A
{
    int v;
    LL w;
    bool operator < (const A& o) const{
        return w > o.w;
    }
};
vector<pair<int, LL>> adj[N];
bool visited[N];

LL prim()
{
    LL sum = 0;
    priority_queue<A> pq;
    pq.push({1, 0});
    while(!pq.empty()){
        A now = pq.top();
        pq.pop();
        if(visited[now.v]){
            continue;
        }
        visited[now.v] = true;
        sum += now.w;
        for(auto x: adj[now.v]){
            pq.push({x.first, x.second});
        }
    }
    return sum;
}
int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    cout << prim();
    return 0;
}