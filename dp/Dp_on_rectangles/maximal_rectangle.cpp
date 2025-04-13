#include<bits/stdc++.h>
using namespace std;


class Solution {
    int helper(vector<int>& heights) {
         stack<int>st;
        int n=heights.size();
        int maxi=INT_MIN;
        for(int i=0;i<=n;i++){
        while(!st.empty()&& (i==n || heights[st.top()]>=heights[i])){
            int he=heights[st.top()];
            st.pop();
            int w=0;
            if(st.empty())w=i;
            else{
                w=i-st.top()-1;
            }
            maxi=max(maxi,he*w);
        }
        st.push(i);
        }
        return maxi;
        // stack<int> s1, s2;
        // int n = v.size();
        
        // // NSL (Nearest Smaller to Left)
        // vector<int> nsl(n);
        // for (int i = 0; i < n; i++) {
        //     while (!s1.empty() && v[i] <= v[s1.top()]) {
        //         s1.pop();
        //     }
        //     nsl[i] = s1.empty() ? -1 : s1.top();
        //     s1.push(i);
        // }

        // // NSR (Nearest Smaller to Right)
        // vector<int> nsr(n);
        // for (int i = n - 1; i >= 0; i--) {
        //     while (!s2.empty() && v[i] <= v[s2.top()]) {
        //         s2.pop();
        //     }
        //     nsr[i] = s2.empty() ? n : s2.top();
        //     s2.push(i);
        // }

        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     int h = v[i];
        //     int w = nsr[i] - nsl[i] - 1;
        //     ans = max(ans, h * w);
        // }
        // return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    
     int n = matrix.size();
     int m = matrix[0].size();
        if (matrix.empty() || matrix[0].empty())
            return 0;

           vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            v[0][i] = matrix[0][i] - '0';
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    v[i][j] = 0;
                } else {
                    v[i][j] = 1 ;
                }
            }
        }

     vector<int>h(m,0);
     int maxarea=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==1)h[j]++;
            else h[j]=0;  
        }
        int area=helper(h);
        maxarea=max(maxarea,area);
     }

        // Convert matrix to a histogram representation
     

        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     ans = max(ans, helper(v[i]));
        // }

         return maxarea;
    }
};
