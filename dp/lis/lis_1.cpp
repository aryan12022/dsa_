#include<bits/stdc++.h>
using namespace std;

class Solution {
    int f(int ind,int prev,vector<int>&arr,vector<vector<int>>&dp){
        int n=arr.size();
       if(ind>=n)return 0;
      if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
      int nottake=f(ind+1,prev,arr,dp);
      int take=0;
      if(prev==-1 || arr[ind]>arr[prev]){
        take=1+f(ind+1,ind,arr,dp);
      }
      return dp[ind][prev+1]=max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
                // int n=nums.size();
                // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//     for(int i=0;i<n;i++){
// dp[n][i]=0;
//     }
    // for(int i=n-1;i>=0;i--){
    //     for(int j=i-1;j>=-1;j--){//j==prev index
    //         int nottake=dp[i+1][j+1];
    //         int take=0;
    //         if( j==-1 || nums[i]>nums[j]){
    //             take=1+dp[i+1][i+1];
    //         }
    //         dp[i][j+1]=max(take,nottake);
    //     }
    // }

    //             return dp[0][-1+1];

 int n=nums.size();
    //             vector<int>cur(n+1,0),next(n+1,0);

    //  for(int i=n-1;i>=0;i--){
    //     for(int j=i-1;j>=-1;j--){//j==prev index
    //         int nottake=next[j+1];
    //         int take=0;
    //         if( j==-1 || nums[i]>nums[j]){
    //             take=1+next[i+1];
    //         }
    //         cur[j+1]=max(take,nottake);
    //     }
    //     next=cur;
    // }

    //             return cur[-1+1];
    vector<int>dp(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(nums[prev]<nums[i])
            dp[i]=max(dp[i],1+dp[prev]);
        }
        maxi=max(maxi,dp[i]);
    }
return maxi;
    }
};