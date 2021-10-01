/*
	Task		: Kth_Inversion
	Author		: Phumipat C. [MAGCARI]
	Language	: C++
	Explanation	: 
	Created		: 01 October 2021 [10:03]
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

const int N = 100010;	//N is number of element
int tree[N];

void upd(int idx,int v){
	for(;idx<N;idx+=idx&-idx)
		tree[idx]+=v;
}

int read(int idx,int sum = 0){
	for(;idx>0;idx-=idx&-idx)
		sum+=tree[idx];
	return sum;
}

vector<LL > comp_number(vector<LL > a){
	vector<LL > b = a;
	sort(all(b)),b.resize(unique(all(b))-b.begin());
	for(auto &x:a)
		x = lower_bound(all(b),x)-b.begin();
	return a;
}

pair<LL ,LL > kth_inversion(vector<LL > a,LL k){
	vector<LL > b = comp_number(a);
	for(auto x:b)
		upd(x,1);
	for(int i=0;i<a.size();i++){
		int num = read(b[i]-1);
		if(k>num){
			k-=num;
			continue;
		}
		int idx = i+1;
		while(k){
			if(a[idx]<a[i] && --k == 0)	return {a[i],a[idx]};
			idx++;
		}
	}
	return {-1, -1};	//No K-th inversions found!
}