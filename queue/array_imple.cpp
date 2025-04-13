// queue using arrays
#include<bits/stdc++.h>
using namespace std;
class queueImpl{
    int cnt=0;
   int size=10;int q[10];int start=-1,end=-1;int cursize=0;
   void push(int x){
    if(cursize==size)cout<<"not possible";
    if(cursize==0){
        start=0;end=0;
    }else{
        end=(end+1)%size;
    }
    q[end]=x;cursize+=1;
   }



   //this is 
   void pop(){
    if(cursize==0)cout<<"not possible";
    cnt=q[start];
    if(cursize==1)start=end=-1;
    else{
        start=(start+1)%size;
    }
    cursize-=1;
   }
   int top(){
    if(cursize==0)cout<<" ";
    return q[start];
   }
   int size(){
    return cursize;
   }
 

};

