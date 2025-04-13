#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int mini=prices[0];
            int result=0;
            int maxprofit=0;
            for(int i=1;i<n;i++){
              result=prices[i]-mini;
             maxprofit=max(maxprofit,result);
             mini=min(mini,prices[i]);
            }
    return maxprofit;
    
        }
    };