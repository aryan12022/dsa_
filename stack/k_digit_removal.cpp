#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeKdigits(string num, int k) {
    //         stack<int>st;
    //         for(auto it:num){
    //             while(!st.empty() && k>0 && st.top()>it){
    //                 st.pop();
    //                 k--;
    //             }
    //             st.push(it);
    //         }
    //         // if some k is left
    //         while(k>0 && !st.empty()){
    //             st.pop();
    //             k--;
    //         }
    //         string result;
    // while(!st.empty()){
    //     result+=st.top();
    //     st.pop();
    // }
    // reverse(result.begin(),result.end());
     
    
    // // if string is 0000.. then return 0
    // ///if 0001234 then remove first zeroes;
    //         size_t pos = result.find_first_not_of('0');
    //         result = (pos == std::string::npos) ? "0" : result.substr(pos);
    //         return result;
    stack<int>st;
    for(auto it:num){
        while(!st.empty()&& k>0 && (st.top()-'0' > it-'0')){
            st.pop();
            k--;
        }
        st.push(it);
    }
         while(k>0 && !st.empty()){
            st.pop();
            k--;
         }
    
         string res="";
         while(!st.empty()){
            res+=st.top();
            st.pop();
         }
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.size()==0)return "0";
        else return res;
    
    
    
        }
    };