/*
	Task	: _Rabin_Karp
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Created	: 04 May 2021 [16:45]
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
char a[N],b[N];
// Check if String b is existed in String a
int rabin_karp(){
	int n = strlen(a),m = strlen(b);
	if(m>n)	return 0;	// Not found!
	int ha = 0,hb = 0,v = 1;
	for(int i=0;i<m;i++){
		ha = ((ha*29)+(a[i]-'a'))%MOD;
		hb = ((hb*29)+(b[i]-'a'))%MOD;
	}
	for(int i=1;i<m;i++)
		v = (v*29)%MOD;
	for(int i=0;i<=n-m;i++){
		if(ha == hb){
			for(int j=0;j<m;j++){
				if(b[j] != a[i+j])	break;
				if(j == m-1)		return 1;
			}
		}
		ha-=(v*(a[i]-'a'))%MOD;
		ha+=MOD,ha%=MOD;
		ha = ((ha*29)+(a[i+m]-'a'))%MOD;
	}
	return 0;
}
int main(){
	cin >> a >> b;
	cout << rabin_karp();
	return 0;
}