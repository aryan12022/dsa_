#include<bits/stdc++.h>
using namespace std;

class stackIMPL{
int top=-1;int st[10];
public:
void push(int x){
   if(top>=10)cout<<"not possible";
   top=top+1;
   st[top]=x;
}
int topi(){
    if(top==-1){
        return -1;
    }
    return st[top];
}
void pop(){
    if(top<0)cout<<"not possible"<<endl;
    top=top-1;
}
int size(){
    return top+1;
}
};  