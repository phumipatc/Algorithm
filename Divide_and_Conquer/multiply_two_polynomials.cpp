/*
	Task	: Mod_of_Power
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Explanation Link : https://www.geeksforgeeks.org/multiply-two-polynomials-2/
	Created	: 03 May 2021 [15:15]
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



int *multiply(int A[], int B[], int m, int n)
{
   int *prod = new int[m+n-1];
  
   for (int i = 0; i<m+n-1; i++)
     prod[i] = 0;

   for (int i=0; i<m; i++)
   {
     for (int j=0; j<n; j++)
         prod[i+j] += A[i]*B[j];
   }
  
   return prod;
}

void printPoly(int poly[], int n)
{
    for (int i=0; i<n; i++)
    {
       cout << poly[i];
       if (i != 0)
        cout << "x^" << i ;
       if (i != n-1)
       cout << " + ";
    }
}