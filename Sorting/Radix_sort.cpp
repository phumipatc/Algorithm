/*
	Task		: Radix_sort
	Author		: PunnyOz2
	Language	: C++
	Explanation	: 
	Created		: 01 October 2022 [13:56]
*/
#include<bits/stdc++.h>
using namespace std;
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