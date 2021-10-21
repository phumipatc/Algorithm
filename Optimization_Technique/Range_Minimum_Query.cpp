/*
	Task		: Finding max value in range [st, en] with Range_Minimum_Query
	Author		: Phumipat C. [MAGCARI]
	Language	: C++
	Explanation	: 
	Created		: 01 October 2021 [10:55]
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
int maxx[20][N];

void init(int n,vector<int > a){
	for(int i=0;i<n;i++)
		maxx[0][i] = a[i];
	for(int i=1;i<=log2(n);i++)
        for(int j=0;j+(1<<i)-1<n;j++)
            maxx[i][j]=max(maxx[i-1][j],maxx[i-1][j+(1<<(i-1))]);
}

int read(int st,int en){
	int k = log2(en-st+1);
	return max(maxx[k][st],maxx[k][en-(1<<k)+1]);
}