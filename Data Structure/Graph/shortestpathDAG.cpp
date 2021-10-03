#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

void findtoposort(int node,vector<pair<int,int>>adj[],stack<int>&stk,vector<int>&vis){
    vis[node]=1;
    for(auto itr: adj[node]){
        if(!vis[itr.first]){
            findtoposort(itr.first,adj,stk,vis);
        }

    }
    stk.push(node);
}


void shortestpath(int N,vector<pair<int,int>>adj[],int s){

    stack<int> st;
    vector<int>vis(N+1,0);
    for(int i=0;i<N;i++){
        if(!vis[i]){
            findtoposort(i,adj,st,vis);
        }
    }
    vector<int> dist(N,INT_MAX);
    dist[s]=0;
    while (!st.empty())
    {
        int node=st.top();
        st.pop();
        if(dist[node]!= INF){
            for(auto itr:adj[node]){
                if(dist[node]+itr.second < dist[itr.first]){
                    dist[itr.first]=dist[node]+itr.second;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<pair<int,int>>adj[V+1];
        for(int i=0;i<E;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
        }

        int s;
        cin>>s;
        shortestpath(V, adj,s);

    }
}