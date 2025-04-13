#include<bits/stdc++.h>
using namespace std;
int priority(char a){
  if(a=='^')return 3;
  else if(a=='*' || a=='/' )return 2;
  else if(a=='+' || a=='-')return 1;
  else return -1;
}

string Infix_to_postfix(string s){
    int i=0;string ans="";stack<char>st;
    int n=s.size();
    while(i<n){
        if(s[i]>='A' && s[i]<='Z' ||s[i]>='a' && s[i]<='z' ||s[i]>='0' && s[i]<='9' ){
            ans=ans+s[i];
        }else if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            while(!st.empty()  && st.top()!='(' ){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && priority(s[i])<=priority(st.top())){
               ans+=st.top();
               st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans+=st.top();

        st.pop();
    }
    return ans;
}
