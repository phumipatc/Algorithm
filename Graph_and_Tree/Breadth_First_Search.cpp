/*
	Task	: Breadth First Search
	Author	: Borworntat D. [Hydrolyzed~]
	School	: RYW
	Language: C++
	Created	: 10 Aug 2021 [12:30]
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
vector<int> adj[N];
bool visited[N];

void bfs(int source){
	memset(visited, false, sizeof visited);
	queue<int> q;
	q.push(source);
	visited[source] = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for(auto x: adj[now]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
			}
		}
	}
}
