//brute force 
const int mod=1e9+7;
# include<bits/stdc++.h>
using namespace std;
// int main(){
// int n;int arr[n];

// int sum=0;int mini=0;
// for(int i=0;i<n;i++){
//     mini=arr[i];
//     for(int j=i;j<n;j++){
//         mini=min(mini,arr[j]);
//         sum=(sum+mini)%mod;
//     }
// }
// return sum; 
// }


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
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n = arr.size();
       vector<int>nse=findnse(arr);
       
     vector<int>pse= findpse(arr);
       long long  int total=0;
for(int i=0;i<n;i++){
    long long int right=nse[i]-i;
    long long int left=i-pse[i];
    total=(total+(left*right*1ll*arr[i])%mod)%mod;
}
return total;

    }
};