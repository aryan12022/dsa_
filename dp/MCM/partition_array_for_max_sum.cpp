#include <bits/stdc++.h>
using namespace std;




class Solution {
    long long f(int ind, vector<int>& nums, vector<long long>& dp, int k) {
        int n = nums.size();
        if (ind == n) return 0;
        if (dp[ind] != -1) return dp[ind];

        long long ans = 0;
        int maxelement = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++) {
            maxelement = max(maxelement, nums[j]);
            int len = j - ind + 1;
            long long temp = (long long)maxelement * len + f(j + 1, nums, dp, k);
            ans = max(ans, temp);
        }

        return dp[ind] = ans;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
         long long ans = 0;
        vector<long long> dp(n+1, 0);
        for( int ind=n-1;ind>=0;ind--){
        int maxelement = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++) {
            maxelement = max(maxelement, arr[j]);
            int len = j - ind + 1;
            long long temp = (long long)maxelement * len + dp[j+1];
            ans = max(ans, temp);
        }
        dp[ind]=ans;
        }

        return (int)dp[0];
    }
};
