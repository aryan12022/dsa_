#include <bits/stdc++.h>
using namespace std;
class Solution {
    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
          int mini=INT_MIN;
        if(i>j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
        for(int ind=i;ind<=j;ind++){
            int steps=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
            mini=max(mini,steps);
        }
        return dp[i][j]=mini;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
//        int maxi=INT_MIN;
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    nums.push_back(1);
    nums.insert(nums.begin(),1);
//   for(int i=n;i>=1;i--){
//     for(int j=0;j<=n;j++){
  
//         if(i>j) continue;//as initisalised by 0
      
//         for(int ind=i;ind<=j;ind++){
//             int steps=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums)+f(ind+1,j,nums);
//           maxi=max(maxi,steps);
//         }
//         dp[i][j]=maxi;
//     }
//   }


  return f(1,n,nums,dp);
    }
};