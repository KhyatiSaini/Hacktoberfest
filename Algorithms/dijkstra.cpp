#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; //n corresponds to number of vertices and m corresponds to number of edges
    cin >> n >> m;

    /*Here a array of vector of pair is taken because the second value in the pair will be the weight of edges*/
    vector<pair<int, int>> adj[n + 1]; 

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    int inf = 1e+7;
    int dist[n + 1]; // This distance array is to store the distance of all nodes from source , initialized with a very large value
    for (int i = 0; i <= n; i++)
    {
        dist[i] = inf;
    }

    int source;
    cin >> source;
    dist[source] = 0;

    bool marked[n + 1]; //This marked array will keep track of all nodes which have been visited , this will also tell us now the node has been visited so we cant get any shorter distance of that node

    memset(marked, false, sizeof(marked));

    for (int i = 1; i <= n; i++)
    {
        int j = -1, min = inf;

        /*in this for loop we'll look for a next smaller value which is closest to source and will mark it as true in first iteratiion of this loop we'll get the source itself , because source to source distance is 0 , then in each iteration we'll get the next shorter distance and so on */

        for (int itr = 1; itr <= n; itr++)
        {
            if (marked[itr] == false && dist[itr] < min)
            {
                j = itr;
                min = dist[j];
            }
        }

        marked[j] = true; // Here the node we get is marked true;
        for (int it = 0; it < adj[j].size(); it++)
        {
            int f = adj[j][it].first; // Getting the pair 
            int w = adj[j][it].second;

            /*Here we'll check that the distance which has been calculated till now is shorter or not from the source if any other route is found we'll replace it , also the marked status will come handy now as all the marked nodes will get automatically disqualified to go in if condition*/
            
            if ((dist[j] + w) < dist[f] && marked[f] == false) 
            {
                dist[f] = dist[j] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}
