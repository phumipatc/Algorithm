/*
	Task		: Counting_sort
	Author		: PunnyOz2
	Language	: C++
	Explanation	: 
	Created		: 01 October 2022 [14:20]
*/
#include<bits/stdc++.h>
using namespace std;
void countingSort(int* start, int* end){
    int* temp = start;
    int Max = *max_element(start, end);
    int Min = *min_element(start, end);
    int range = Max - Min + 1;
    vector<int> cnt(range);
    for(int* i = start; i != end; i++){
        cnt[*i - Min]++;
    }
    for(int i = 0; i < range; i++){
        while(cnt[i]--){
            *temp = i + Min;
            temp++;
        }
    }
}