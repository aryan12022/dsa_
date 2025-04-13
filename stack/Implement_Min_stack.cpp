#include<bits/stdc++.h>
using namespace std;
class  minstack{
    public:
    stack<pair<int,int>>st;
       int val;

   void push(int val){
       if(!st.empty())st.push({val,val});
   else st.push({val,min(val,st.top().second)});
   }
  int getMin(){
    st.top().second;
   }
   int top(){
    st.top().first;
   }
};