#include<bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i,int buy,vector<int>&prices){
      int n=prices.size();
      if(i>=n)return 0;
      if(buy){
          return max(-prices[i]+f(i+1,0,prices),f(i+1,1,prices));
      }
          return max(prices[i]+f(i+2,1,prices),f(i+1,0,prices)); 
    }
public:
  int maxProfit(vector<int>& prices) {
        // same like buy and stock 2 but after every sell we have to leave one day for cooldown
//         int n=prices.size();
//         vector<vector<int>>dp(n+2,vector<int>(2,0));
// for(int i=0;i<2;i++){
//     dp[n][i]=0;
// }
// for(int i=n-1;i>=0;i--){
// for(int buy=0;buy<2;buy++){
//     if(buy){
// dp[i][buy]= max(-prices[i]+dp[i+1][0],dp[i+1][1]);
//     }else{
// dp[i][buy]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
//     }
// }

// }


      
//         return dp[0][1];


    int n=prices.size();
      vector<int>cur(2,0);vector<int>front1(2,0);vector<int>front2(2,0);

for(int i=n-1;i>=0;i--){
for(int buy=0;buy<2;buy++){
  if(buy){
cur[buy]= max(-prices[i]+front1[0],front1[1]);
  }else{
cur[buy]=max(prices[i]+front2[1],front1[0]);
  }
  front2=front1;
  front1=cur;
}

}


      
      return cur[1];
  }
};