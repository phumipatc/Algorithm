#include <bits/stdc++.h>
#include<iostream>
#include <bits/stdc++.h>

/*
	Task		    : Fibonacci_search.cpp
	Author		  : Saurabh-2809
	Language	  : C++
	Explanation	:
*/

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define MOD (LL)(1e9 + 7)

using namespace std;
const int dir4[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
const int dir8[2][8] = {{-1, -1, -1, 0, 1, 1, 1, 0}, {-1, 0, 1, 1, -1, 0, 1, -1}};

using namespace std;

int min(int x, int y) { return (x <= y) ? x : y; }
   
int fibMonaccianSearch(int arr[], int x, int n)
{

    int fibMMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci
   
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
   
    int offset = -1;
   
    while (fibM > 1) {
        
        int i = min(offset + fibMMm2, n - 1);
   
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
   
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
   
        else
            return i;
    }
   
    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;
   
    return -1;
}

 /* main function for I/O*/
 int main(void)
 {
    int n,i;
    cout<<"\nEnter the total number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array\n";
    for( i=1 ; i<n ; i++ )
    {
        cin>>arr[i];
    }
    int m = sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"\nEnter element to be searched:";
    cin>>x;
    int ind = fibMonaccianSearch(arr, x, n);
    if(ind >= 0)
        cout << "Found at index: " << ind;
    else
        cout << x << " isn't present in the array";
    return 0;
 } 
