//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;






class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp(n, 1), dp2(n, 1);


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j] && dp2[j] + 1 > dp2[i]) {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }

    
      int maxBitonic = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > 1 && dp2[i] > 1) {  // Ensure both increasing and decreasing parts exist
                maxBitonic = max(maxBitonic, dp[i] + dp2[i] - 1);
            }
        }
        return maxBitonic;
    }
};
