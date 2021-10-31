#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    stack<char> st;
    bool ans=false;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-' || s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                ans=true;//as there is no operator between the 2 brackets
            }
            while(!st.empty() && (st.top()=='*' || st.top()=='/' || st.top()=='+' || st.top()=='-')){
                st.pop();
            }
            st.pop();
        }
    }
    cout<<ans;
    return 0;
}