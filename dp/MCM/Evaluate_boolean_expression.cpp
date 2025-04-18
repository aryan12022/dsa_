
///coding ninjas ka solution h
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
#define ll long long

long long   f(int i,int j,int isTrue,string &exp, vector<vector<vector<ll>>>&dp){
    if(i>j)return 0;
    if(i==j){
        if(isTrue==1){
            return (exp[i]=='T');
        }else {return (exp[i]=='F');}
    }

    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    ll ways=0;
    for(int ind=i+1;ind<=j-1;ind+=2){
           ll lt=f(i,ind-1,1,exp,dp)%mod;
           ll lf=f(i,ind-1,0,exp,dp)%mod;
           ll rt=f(ind+1,j,1,exp,dp)%mod;
           ll rf=f(ind+1,j,0,exp,dp)%mod;


           if(exp[ind]=='&'){
               if(isTrue){
                   ways=(ways+(rt*lt)%mod)%mod;
               }else{
                   ways=(ways+(lt*rf)%mod +(lf*rt)%mod + (lf *rf)%mod)%mod;
               }
           }else if(exp[ind]=='|'){
               if(isTrue){
                   ways=(ways+(lt*rt)%mod +(lt*rf)%mod + (lf*rt)%mod)%mod;
               }else{
                   ways=(ways+(lf*rf)%mod)%mod;
               }
           }else if (exp[ind] == '^') {
    if (isTrue) {
        ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
    } else {
        ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;  
    }
}

    }
    return dp[i][j][isTrue]=ways;

}

int evaluateExp(string & exp) {
    int n=exp.size();
    vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return f(0,n-1,1,exp,dp);
}