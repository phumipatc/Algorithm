/*
	Task		: Insertion Sort
	Author		: Nikhil Gautam
	Language	: C++
	Explanation	: https://www.geeksforgeeks.org/insertion-sort/
*/
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define MOD (LL)(1e9 + 7)
using namespace std;
const int dir4[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
const int dir8[2][8] = {{-1, -1, -1, 0, 1, 1, 1, 0}, {-1, 0, 1, 1, -1, 0, 1, -1}};


void display(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void insertsort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1,temp=a[i];
        while(a[j]>temp && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    insertsort(a,n);
    display(a,n);
    return 0;
}
