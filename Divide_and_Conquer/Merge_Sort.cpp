/*
	Task		: Merge_Sort
	Author		: Phumipat C. [MAGCARI]
	School		: RYW
	Language	: C++
	Explanation	: https://www.geeksforgeeks.org/merge-sort/
	Created		: 03 May 2021 [19:55]
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

const int N = 100010;
int a[N],b[N];
void merge_sort(int l,int r){
	if(l == r)	return ;
	int mid = (l+r)/2;
	merge_sort(l,mid),merge_sort(mid+1,r);
	int i = l,j = mid+1,k=l;
	while(i<=mid && j<=r){
		if(a[i]<=a[j])	b[k++] = a[i++];
		else			b[k++] = a[j++];
	}
	while(i<=mid)	b[k++] = a[i++];
	while(j<=r)		b[k++] = a[j++];
	for(int k=l;k<=r;k++)
		a[k] = b[k];
}