#include<bits/stdc++.h>
using namespace std;

class st{
queue<int>q;
public:
void push(int x){
int s=q.size();
q.push(x);

for(int i=1;i<=s;i++){
q.push(q.front());
q.pop();
}
  }

  void pop(){
    q.pop();
  }
  int top(){
    return q.front();
  }
};