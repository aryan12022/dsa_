#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            
          int n=prices.size();
            vector<int>cur(2,0);vector<int>front1(2,0);
    
    for(int i=n-1;i>=0;i--){
    for(int buy=0;buy<2;buy++){
        if(buy){
    cur[buy]= max(-prices[i]+front1[0],front1[1]);
        }else{
    cur[buy]=max(prices[i]-fee +front1[1],front1[0]);
        }
    
        front1=cur;
    }
    
    }      
            return cur[1];
        }
    };