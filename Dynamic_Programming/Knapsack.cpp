/*
	Task		: Knapsack
	Author		: Phumipat C. [MAGCARI]
	Language	: C++
	Explanation	: 
	Created		: 22 August 2021 [11:15]
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
int dp[N];					//dp[i] means max value when weight = i
pair<int ,int > items[N];	//first = value, second = weight

int knapsack_no_repeated_item_allowed(int n,int max_weight){
	fill(dp,dp+N,-1e9);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=max_weight;j>=items[i].second;j--){
			if(dp[j-items[i].second] == -1e9)	continue;
			dp[j] = max(dp[j],dp[j-items[i].second] + items[i].first);
		}
	}
	int maxx = -1e9;
	for(int i=0;i<=max_weight;i++)
		maxx = max(maxx,dp[i]);
	return maxx;
}

int knapsack_repeated_item_allowed(int n,int max_weight){
	fill(dp,dp+N,-1e9);
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=items[i].second;j<=max_weight;j++){
			if(dp[j-items[i].second] == -1e9)	continue;
			dp[j] = max(dp[j],dp[j-items[i].second] + items[i].first);
		}
	}
	int maxx = -1e9;
	for(int i=0;i<=max_weight;i++)
		maxx = max(maxx,dp[i]);
	return maxx;
}