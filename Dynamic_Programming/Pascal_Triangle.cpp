/*
	Task		: Pascal_Triangle
	Author		: Phumipat C. [MAGCARI]
	Language	: C++
	Explanation	: 
	Created		: 22 August 2021 [11:26]
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

const int N = 1010;
int nCr[N][N];	//nCr[i][j] means n = i, r = j [iCj]

void init_triangle(int n){
	for(int i=0;i<=n;i++){
		nCr[i][0] = nCr[i][i] = 1;
		for(int j=1;j<i;j++)
			nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
	}
}
