/*
	Task	: Kahn's Algorithm
	Author	: Borworntat D. [Hydrolyzed~]
	School	: RYW
	Language: C++
	Created	: 11 Aug 2021 [14:17]
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
int in[N];

// Kahn's Algorithm
void kahn(int nodes){
	queue<int> q;
	for(int i=1; i<=nodes; ++i){
		if(!in[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		cout << now << " " ;
		for(auto x: adj[now]){
			in[x] -= 1;
			if(in[x] == 0){
				q.push(x);
			}
		}
	}
}

int main(){
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		in[v]++;
	}
	kahn(n);
	return 0;
}