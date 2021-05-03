/*
	Task	: KMP [Knuth Morris Pratt]
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 03 May 2021 [15:19]
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
char A[N],B[N];
int pos[N];
int KMP(){	// Check if String B found in String A
	int n = strlen(A+1),m = strlen(B+1),j = 0;
	for(int i=2;i<=m;i++){
		while(j>0 && B[j+1]!=B[i])	j = pos[j];
		if(B[j+1] == B[i])	j++;
		pos[i] = j;
	}
	j = 0;
	for(int i=1;i<=n;i++){
		while(j>0 && B[j+1]!=A[i])	j = pos[j];
		if(B[j+1] == A[i])	j++;
		if(j == m)
			return 1;	// Found!
	}
	return 0;	// Not found!
}