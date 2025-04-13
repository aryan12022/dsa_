#include <bits/stdc++.h>
using namespace std;


class Solution {
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
    
    
        int f(int i,int n,string &s,vector<int>&dp){
          
           if(i==n )return 0;
           int mincost=INT_MAX;
           if(dp[i]!=-1)return dp[i];
           for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
               
               int cost=1+f(j+1,n,s,dp);
                mincost=min(cost,mincost);
            }
           }
           return dp[i]=mincost;
        }
    public:
        int minCut(string s) {
            int n=s.size();
          
            vector<int>dp(n+1,0);
    
    
    for(int i=n-1;i>=0;i--){
        int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost=1+dp[j+1];
                mincost=min(mincost,cost);
            }
        }
        dp[i]=mincost;
    }
    
    
    
    
            return dp[0]-1;
        }
    };