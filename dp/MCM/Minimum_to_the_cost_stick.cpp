
#include<bits/stdc++.h>
using namespace std;


class Solution {

    int f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){

        if(i>j)return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int ind=i;ind<=j;ind++){
            int steps=cuts[j+1]-cuts[i-1]+
            f(i,ind-1,cuts,dp)+
            f(ind+1,j,cuts,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini; 
    }
public:
    int minCost(int n, vector<int>& cuts) {
              int c=cuts.size();
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
  
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());

        return f(1,c,cuts,dp);
    }
};

