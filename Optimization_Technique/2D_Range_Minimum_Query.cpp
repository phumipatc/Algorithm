/*
	Task		: 2D Range Minimum Query
	Author		: Borworntat D. [Hydrolzed~]
	School		: RYW
	Language	: C++
	Explanation	: https://codeforces.com/blog/entry/45485
	Created		: 01 October 2022 [12:31]
*/

#include <bits/stdc++.h>
using namespace std;

const int MxN = 1010;
const int LgN = 16;
int sparse_table[LgN][LgN][MxN][MxN],  lg[MxN];

void init(std::vector<std::vector<int>> arr){
	int n = arr.size();
	for(int state=2; state<MxN; ++state){
		lg[state] = lg[state >> 1] + 1;
	}
	memset(sparse_table, 0x3f, sizeof sparse_table);
	// base case
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			sparse_table[0][0][i][j] = arr[i][j];
		}
	}
	// precompute
	for(int state_i=0; state_i<LgN; ++state_i){
		for(int state_j=0; state_j<LgN; ++state_j){
			if(state_i + state_j == 0){
				continue;
			}
			for(int i=0; i+(1 << state_i)<=n; ++i){
				for(int j=0; j+(1 << state_j)<=n; ++j){
					if(state_i == 0){
						sparse_table[state_i][state_j][i][j] = min(sparse_table[state_i][state_j - 1][i][j], sparse_table[state_i][state_j - 1][i][j + (1 << (state_j - 1))]);
					}
					else{
						sparse_table[state_i][state_j][i][j] = min(sparse_table[state_i - 1][state_j][i][j], sparse_table[state_i - 1][state_j][i + (1 << (state_i - 1))][j]);
					}
				}
			}
		}
	}
}

int query(int a, int b, int c, int d){
	swap(c, b);
	c++, d++;
	int state_i = lg[c - a], state_j = lg[d - b];
	int A = sparse_table[state_i][state_j][a][b];
	int B = sparse_table[state_i][state_j][c - (1 << state_i)][b];
	int C = sparse_table[state_i][state_j][a][d - (1 << state_j)];
	int D = sparse_table[state_i][state_j][c - (1 << state_i)][d - (1 << state_j)];
	return min({A, B, C, D});
}
