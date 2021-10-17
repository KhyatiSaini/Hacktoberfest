#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

class Stack{

public:
queue<int> q1,q2;

void push(int n){

q2.push(n);

while (!q1.empty())
{
    int x=q1.front();
    q1.pop();
    q2.push(x);
}

if(q1.empty()){
queue<int> q;
 q=q2;
 q2=q1;
 q1=q;

}

}


void pop(){

int x=q1.front();
q1.pop();
cout<<x<<endl;

}

};

int main(){
ios_base::sync_with_stdio(false);
Stack s;
s.push(4);
s.push(3);
s.push(2);
s.push(1);
s.pop();
s.pop();
s.pop();
s.pop();
return 0;
}
