/*
	Task	: Tree_Traversal
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 06 May 2021 [14:01]
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
	int l,r;
};
A a[N];
void prefix(int u){
	cout << u << ' ';
	prefix(a[u].l);
	prefix(a[u].r);
}
void infix(int u){
	cout << u << ' ';
	infix(a[u].l);
	infix(a[u].r);
}
void postfix(int u){
	postfix(a[u].l);
	postfix(a[u].r);
	cout << u << ' ';
}