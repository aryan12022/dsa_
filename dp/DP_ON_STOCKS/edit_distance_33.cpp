#include<bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){ 
            return f(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=(1+min(f(i-1,j,s,t,dp),min(f(i,j-1,s,t,dp),f(i-1,j-1,s,t,dp))));

    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=i;//for any i , col is fixed
    for(int i=0;i<=m;i++)dp[0][i]=i;//for any i, col is fixed

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
if(word1[i-1]==word2[j-1]){
            dp[i][j]=dp[i-1][j-1];
        }else
    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));

            }
        }
        return dp[n][m];
    }
};