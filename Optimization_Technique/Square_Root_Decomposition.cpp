/*
	Task		: Square_Root_Decomposition
	Author		: Phumipat C. [MAGCARI]
	School		: RYW
	Language	: C++
	Explanation	: https://www.geeksforgeeks.org/sqrt-square-root-decomposition-technique-set-1-introduction/
	Created		: 08 May 2021 [10:51]
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
const int sqN = 320;
int cluster[sqN];
int a[N];
int main(){
	int n,m;
	// array starts from 0 -> n-1
	cin >> n >> m;
	while(m--){
		int opr;
		cin >> opr;
		if(opr == 1){
			// Change value
			int idx,v;
			cin >> idx >> v;
			a[idx] = v;
			// change current cluster value
			cluster[idx/sqN] = -1e9;
			for(int i=(idx/sqN)*sqN;i<min((idx/sqN)*sqN + sqN,n);i++)
				cluster[idx/sqN] = max(cluster[idx/sqN],a[i]);
		}else if(opr == 2){
			// ask max value in range [l,r]
			int l,r;
			cin >> l >> r;
			int maxx = -1e9;
			for(int i=l;i<=r;){
				if(i%sqN || i+sqN-1>r){
					maxx = max(maxx,a[i]);
					i++;
				}else{
					maxx = max(maxx,cluster[i/sqN]);
					i+=sqN;
				}
			}
			cout << maxx << '\n';
		}
	}
	return 0;
}