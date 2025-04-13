#include<bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i,int tra,int k,vector<int>&prices,   vector<vector<int>>&dp){
        int n=prices.size();
        if(i==n || tra==2*k)return 0;
if(dp[i][tra]!=-1)return dp[i][tra];    
 if(tra%2==0){//buy
            return dp[i][tra]=max(-prices[i]+f(i+1,tra+1,k,prices,dp),f(i+1,tra,k,prices,dp));
        }else{
         return dp[i][tra]= max(prices[i]+f(i+1,tra+1,k,prices,dp),f(i+1,tra,k,prices,dp));
        }
    }
public:
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        // for(int i=0;i<=n;i++){
        //     for(int buy=0;buy<=1;buy++){//base case
        //        dp[i][buy][0]=0;
        //     }
        // }
        //   for(int buy=0;buy<2;buy++){
        //     for(int cap=0;cap<2;cap++){//base case
        //        dp[0][buy][cap]=0;
        //     }
        // }
for(int i=n-1;i>=0;i--){
    for(int tra=2*k-1;tra>=0;tra--){
            if(tra%2==0){//buy
            dp[i][tra]=max(-prices[i]+dp[i+1][tra+1],dp[i+1][tra]);
        }else{
         dp[i][tra]= max(prices[i]+dp[i+1][tra+1],dp[i+1][tra]);
        }
    
}
    }
   return dp[0][0];
    }
};