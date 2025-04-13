#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool compare(string &a, string &b) {
        if (a.size() != b.size()+1 ) return false;
        int first = 0;
        int second = 0;
        while (first < a.size()) {
            if (a[first] == b[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        return first == a.size() && second == b.size();
    }

public:
    int longestStrChain(vector<string>& words) {
      
        sort(words.begin(), words.end(), [](string &s1, string &s2) {
            return s1.size() < s2.size();  
        });

        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (compare(words[i], words[j]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
