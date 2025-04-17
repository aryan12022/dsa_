#include<bits/stdc++.h>
using namespace std;
vector<int> findnse(vector<int>&arr){
    int n=arr.size();stack<int>st;
    vector<int>nse(n);
    for(int i=n-1;i>=0;i--){
    while(!st.empty() && arr[st.top()]>=arr[i]){
st.pop();
    }
    nse[i]=st.empty()?n:st.top();
st.push(i);
    }
    return nse;
}

vector<int> findpse(vector<int>&arr){
    int n=arr.size();stack<int>st;
    vector<int>pse(n);
    for(int i=0;i<n;i++){
    while(!st.empty() && arr[st.top()]>arr[i]){
st.pop();
    }
    pse[i]=st.empty()?-1:st.top();
st.push(i);
    }
    return pse;
}   
   
   
   
   long long  int sumSubarrayMins(vector<int>& arr) {
       int n = arr.size();
       vector<int>nse=findnse(arr);
       
     vector<int>pse= findpse(arr);
       long long  int total=0;
for(int i=0;i<n;i++){
    long long int right=nse[i]-i;
    long long int left=i-pse[i];
    total=total+(left*right*1ll*arr[i]);
}
return total;
    }


vector<int> findnge(vector<int>&arr){
    int n=arr.size();stack<int>st;
    vector<int>nge(n);
    for(int i=n-1;i>=0;i--){
    while(!st.empty() && arr[st.top()]<=arr[i]){
st.pop();
    }
    nge[i]=st.empty()?n :st.top();
st.push(i);
    }
    return nge;
}

vector<int> findpge(vector<int>&arr){
    int n=arr.size();stack<int>st;
    vector<int>pge(n,-1);
    st.push(0);
    for(int i=1;i<n;i++){
    while(!st.empty() && arr[st.top()]<arr[i]){
st.pop();
    }
    pge[i]=st.empty()?-1:st.top();
st.push(i);
    }
    return pge;
}   
   
   
   
   long long  int sumSubarrayMax(vector<int>& arr) {
       int n = arr.size();
       vector<int>nge=findnge(arr);
       
     vector<int>pge= findpge(arr);
       long long  int total=0;
for(int i=0;i<n;i++){
    int right=nge[i]-i;
    int left=i-pge[i];
    total=total+(left*right*1ll*arr[i]);
}
return total;
    }
class Solution {
public:
  
    long long subArrayRanges(vector<int>& nums) {
        long long int ans = sumSubarrayMax(nums) - sumSubarrayMins(nums) ;
        return ans;
    }


};