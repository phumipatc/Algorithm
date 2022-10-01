/*
        Task		: Minimum Coin Change
        Author		: Naravit N. [ADNCRICH]
        School		: Chulalongkorn University
        Language	: C++
        Explanation	: https://www.geeksforgeeks.org/quick-sort/
        Created		: 01 Oct 2022 [15:37]
*/
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define MOD (LL)(1e9 + 7)
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;
const int dir4[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
const int dir8[2][8] = {{-1, -1, -1, 0, 1, 1, 1, 0}, {-1, 0, 1, 1, -1, 0, 1, -1}};
const int N = 1000000, M = 10000;

int dp[N + 20], coins[M + 20];

void minimum_coin_change(int n) {
    for (int i = 0; i < n; i++) cin >> coins[i];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                if (dp[i] == -1)
                    dp[i] = dp[i - coins[j]] + 1;
                else
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
}

int main() {
    int n, q, i;
    cin >> n >> q;
    minimum_coin_change(n);
    while (q--) {
        int x;
        cin >> x;
        cout << dp[x] << "\n";
    }
}