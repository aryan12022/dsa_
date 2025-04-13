


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
      
     vector<int>ans;
     vector<int>dp(n,1);
     vector<int>hash(n);
     int lastindex=0;
     int maxi=1;
     for(int i=0;i<n;i++){
         hash[i]=i;
         for(int prev=0;prev<i;prev++){
             if(arr[prev]<arr[i] && 1+dp[prev]>dp[i]){
                 dp[i]=1+dp[prev];
                 hash[i]=prev;
             }
         }
         if(dp[i]>maxi){
             maxi=dp[i];
             lastindex=i;
             
         }
     }
     ans.push_back(arr[lastindex]);
     while(hash[lastindex]!=lastindex){
         lastindex=hash[lastindex];
         ans.push_back(arr[lastindex]);
     }
     reverse(ans.begin(),ans.end());
     return ans;
    }
};
