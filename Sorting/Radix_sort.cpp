/*
	Task		: Radix_sort
	Author		: PunnyOz2
	Language	: C++
	Explanation	: 
	Created		: 01 October 2022 [13:56]
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
void radixSort(int* start, int* end){
	int* temp = start;
    int Max = *max_element(start, end);
    queue<int> cnt[10];
    for(int i = 1; Max/i > 0; i *= 10){
        for(int* j = start; j != end; j++){
            cnt[(*j/i)%10].push(*j);
        }
        temp = start;
        for(int j = 0; j < 10; j++){
            while(!cnt[j].empty()){
                *temp = cnt[j].front();
                cnt[j].pop();
                temp++;
            }
        }
    }
}