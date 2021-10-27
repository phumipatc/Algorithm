/*
	Task		: Pallindrome Partitioning
	Author		: Dharmik Govani [21Shadow10]
	Language	: C++
	Explanation	: 
	Created		: 27 October 2021 [00:06]
*/
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:


    bool isPallindrome(string str, int i, int j) {
        while(i<=j) {
            if(str[i]!=str[j])
                return false ;
                
            i++ ;
            j-- ;
        }
        
        return true ;
    }

    int solve(int dp[501][501],string str, int i, int j) {
        if(i>=j)
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(isPallindrome(str,i,j))
            return 0;
            
        int ans = INT_MAX ;
        
        for(int k=i;k<j;k++) {
            
            int left = (dp[i][k]==-1?solve(dp,str,i,k):dp[i][k]);
            int right = (dp[k+1][j]==-1?solve(dp,str,k+1,j):dp[k+1][j]) ;
            int temp = left + right + 1;
            
            ans = min(ans,temp) ;
        }
        
        return dp[i][j]=ans ;
    }    

    int palindromicPartition(string str)
    {
        // code here
        
        int n = str.size()-1;
        int dp[501][501] ;
        
        memset(dp,-1,sizeof dp) ;
        
        return solve(dp,str,0,str.size()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends