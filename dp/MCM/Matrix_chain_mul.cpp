//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int f(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
        //base case (only single element left)
        if(i==j)return 0;
        int mini=1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<j;k++){
            int res=(arr[i-1]*arr[k]*arr[j])+f(i,k,arr,dp)+f(k+1,j,arr,dp);
            mini=min(mini,res);
        }
        return dp[i][j]=mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
     int dp[n][n];
           
        
        for(int i=1;i<n;i++)dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            
        for(int j=i+1;j<n;j++){
             int mini=1e9;
        for(int k=i;k<j;k++){
            int res=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
           if(res<mini)mini=res;
        }
         dp[i][j]=mini;
            }
        }
        
        
        
        
        
        return dp[1][n-1];
    }
};
