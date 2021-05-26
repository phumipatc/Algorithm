/*
	Task		: Convex_Hull_Graham_Scan
	Author		: Phumipat C. [MAGCARI]
	School		: RYW
	Language	: C++
	Explanation	: 
	Created		: 26 May 2021 [10:09]
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

const int N = 100010;
struct point{
    long long x,y;
};
point convex[N];
long long dist(point p1,point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int orientation(point p0,point p1,point p2){
    long long res=(p1.y-p0.y)*(p2.x-p0.x)-(p2.y-p0.y)*(p1.x-p0.x);
    if(res<0) return 0;//left turn
    if(res>0) return 1;//right turn
    if(res==0) return 2;//int the same line
}
bool cmp(point p1,point p2){
    int res=orientation(convex[1],p1,p2);
    if(res==0) return true;
    if(res==1) return false;
    if(res==2) return dist(convex[1],p1)<dist(convex[1],p2);
}
point st[N];
vector<point > graham_scan(int n){
	int top = 0;
	for(int i=2;i<=n;i++){
        if(convex[1].x>convex[i].x){
            swap(convex[1],convex[i]);
        }
        else if(convex[1].x==convex[i].x){
            if(convex[1].y<convex[i].y){
                swap(convex[1],convex[i]);
            }
        }
    }
    sort(convex+2,convex+n+1,cmp);
    st[++top] = convex[1];
    st[++top] = convex[2];
    for(int i=3;i<=n;i++){
        while(top>1&&orientation(st[top-1],st[top],convex[i])!=0)	top--;
        st[++top]=convex[i];
    }
    while(orientation(st[top-1],st[top],convex[1])==2)	top--;
	vector<point > ret;
	for(int i=1;i<=top;i++)
		ret.push_back(st[i]);
	return ret;
}