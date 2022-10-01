/*
	Task		: Selection_sort
	Author		: Phumipat C. [MAGCARI]
	Language	: C++
	Explanation	: 
	Created		: 01 October 2022 [13:55]
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
const int N = 10010;
int a[N];
void insertionSort(int n){
	int idx = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(a[j] < a[idx])
				idx = j;
		swap(a[i],a[idx]);
	}
}