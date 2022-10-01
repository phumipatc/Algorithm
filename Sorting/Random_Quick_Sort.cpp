/*
        Task		: Quick Sort
        Author		: Naravit N. [ADNCRICH]
        School		: Chulalongkorn University
        Language	: C++
        Explanation	: https://www.geeksforgeeks.org/quick-sort/
        Created		: 01 Oct 2022 [13:49]
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
const int N = 1000010;

int a[N];

int find_pos(int begin, int end) {
    srand(time(NULL));
    int random = begin + rand() % (end - begin);
    swap(a[random], a[end]);
    int pivot = a[end];
    int pos = begin - 1;
    for (int i = begin; i <= end; i++) {
        if (a[i] < pivot) {
            pos++;
            swap(a[i], a[pos]);
        }
    }
    swap(a[pos + 1], a[end]);
    return pos + 1;
}
void random_quick_sort(int begin, int end) {
    if (begin < end) {
        int pos = find_pos(begin, end);
        random_quick_sort(begin, pos - 1);
        random_quick_sort(pos + 1, end);
    }
}
int main() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    random_quick_sort(0, n - 1);
    for (i = 0; i < n; i++) cout << a[i] << " ";
}