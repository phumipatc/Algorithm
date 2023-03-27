/*
	Task		: Exponential_Search.cpp
	Author		: sumit-awasthi
	Language	: C++
	Explanation	:
*/
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define MOD (LL)(1e9 + 7)

#include<iostream>

using namespace std;
const int dir4[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
const int dir8[2][8] = {{-1, -1, -1, 0, 1, 1, 1, 0}, {-1, 0, 1, 1, -1, 0, 1, -1}};

int binarySearch(int array[], int start, int end, int key) {
   if(start <= end) {
      int mid = (start + (end - start) /2); 
      if(array[mid] == key)
         return mid;
      if(array[mid] > key)
         return binarySearch(array, start, mid-1, key);
         return binarySearch(array, mid+1, end, key);
   }
   return -1;
}

int exponentialSearch(int array[], int start, int end, int key){
   if((end - start) <= 0)
      return -1;
      int i = 1; // as 2^0 = 1
      while(i < (end - start)){
         if(array[i] < key)
            i *= 2; 
         else
            break; 
   }
   return binarySearch(array, i/2, i, key); 
}

int main() {
   int n, searchKey, loc;
   cout << "Enter number of items: ";
   cin >> n;
   int arr[n];
   cout << "Enter items: " << endl;
   for(int i = 0; i< n; i++) {
      cin >> arr[i];
   }
   cout << "Enter search key to search in the list: ";
   cin >> searchKey;
   if((loc = exponentialSearch(arr, 0, n, searchKey)) >= 0)
      cout << "Item found at Index= " << loc << endl;
   else
      cout << "Item is not found in the list." << endl;
  return 0;
}
