#include<bits/stdc++.h>
using namespace std;

void topodfs(int node,vector<int>&vis,stack<int>&stk ,vector<int>adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            topodfs(it,vis,stk,adj);
            }
    }
    stk.push(node);
}


void toposort(int V, vector<int> adj[], stack<int>&stk){

    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            topodfs(i,vis,stk,adj );
            }
    }

}


void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}

int main(){
    int V,E;
    vector<int>adj[V+1];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    stack<int> stk;
    toposort(V,adj,stk);

    vector<int> transpose[V+1];
    for(int i=0;i<E;i++){
        for(auto it : adj[i]){
            transpose[it].push_back(i);
        }
    }
    vector<int>vis(V,0);
    while(!stk.empty()){
        int node=stk.top();
        stk.pop();
        cout<< "SCC:";
        revDfs(node, vis, transpose);
        cout<<endl;

    }

}