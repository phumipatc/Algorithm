/*
	Task	: Inversion_Fenwick_Tree
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [20:06]
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

const int N = 100000;
int tree[N+10];
map<int ,int > mapp;
void upd(int idx){
	for(;idx<=N;idx+=idx&-idx)
		tree[idx]++;
}
int read(int idx,int sum=0){
	for(;idx;idx-=idx&-idx)
		sum+=tree[idx];
	return sum;
}
int inversion_count(vector<int > a){
	vector<int > b = a;
	sort(all(b)),b.resize(unique(all(b))-b.begin());	// compress number and remove duplicate numbers
	for(int i=0;i<sz(b);i++)
		mapp[b[i]] = i+1;
	int cnt = 0;
	for(auto x:a){
		cnt+=read(N)-read(x);
		upd(x);
	}
	return cnt;
}
int main(){
	int n;
	vector<int > a;
	cin >> n;
	a.resize(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << inversion_count(a);
}