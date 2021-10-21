/*
    Task	: Longest_palindromic_Substring
    Author	: Chayanin K. [~Aphrodicez]
    School	: RYW
    Lang	: C++    
    Created	: 21 Oct 2021 [18:36]
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e3 + 10;

char s[MaxN];
bool palindrome[MaxN][MaxN];

char Longest_Palindrome[MaxN];

char* LPS() {
    int n = strlen(s + 1);
    int max_size = 1;
    int start = 1;
    for(int i = 1; i <= n; i++)
        palindrome[i][i] = true;
    for(int i = 1; i <= n - 1; i++) {
        palindrome[i][i + 1] = s[i] == s[i + 1];
        if(palindrome[i][i + 1] && 2 > max_size) {
            max_size = 2;
            start = i;
        }
    }
    for(int sz = 3; sz <= n; sz++) {
        for(int l = 1; l + sz - 1 <= n; l++) {
            int r = l + sz - 1;
            palindrome[l][r] = palindrome[l + 1][r - 1] & (s[l] == s[r]);
            if(palindrome[l][r] && sz > max_size) {
                max_size = sz;
                start = l;
            }
        }
    }
    for(int i = 1, j = start; i <= max_size; i++, j++) {
        Longest_Palindrome[i] = s[j];
    }
	return &Longest_Palindrome[1];
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> (s + 1);
    cout << LPS();
    return 0;
}

/*
banana
abracadabra
*/
