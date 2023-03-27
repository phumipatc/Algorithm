#include<bits/stdc++.h>
using namespace std;

// put sum of subarrays of size sqrt(n) into block array
void preprocess_blocks(vector<int>&arr, vector<int>& block)
{
    int len=block.size();
    
    for(int i=0;i<arr.size();i++)
    {
        block[i/len]+=arr[i];
    }
    
}

int main()
{
    int n;
    //input size of array
    cin>>n;
    
    vector<int> arr(n);
    
    //input array
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    //initialize size of blocks to be sqrt(n)+1
    int len= sqrt(n)+1;  
    vector<int> block( len );
    
    // preprocess blocks with sum
    preprocess_blocks(arr, block);    
    
    int querySize;
    //input total queries
    cin>>querySize;
    
    int l,r;
    //input all the queries
    while(querySize--)
    {
        //1 indexed
        cin>>l>>r;
        l--;
        r--;
        
        int sum=0;
        //traversing l to r efficiently by taking 
        //already calculated sum from block array
        for(int i=l;i<=r;)
        {   
            //if i is the starting index of a block and that block is in 
            //the range l to r then take precalculated sum
            //else take arr[i] to sum
            if(i%len==0 && i+len-1<=r)
            {
                sum+= block[i/len];
                i+=len;
            }
            else
            {
                sum+=arr[i];
                i++;
            }
        }
        
        //output sum
        cout<<sum<<endl;
        
    }
    
    return 0;
}
