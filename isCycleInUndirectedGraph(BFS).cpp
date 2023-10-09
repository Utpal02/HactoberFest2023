#include <bits/stdc++.h>
bool bfs(int i, vector<vector<int>>&adj, vector<int> &vis, vector<int>&parent)
{
    vis[i] = 1;
    queue<int>q;
    q.push(i);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto neighbour:adj[node])
        {
            if(!vis[neighbour])
            {
                vis[neighbour] = 1;
                q.push(neighbour);
                parent[neighbour] = node;
            }
            else if(vis[neighbour] and parent[node] != neighbour)
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<m;i++)
    {
        adj[edges[i][1]].push_back(edges[i][0]);
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(n+1,0);
    vector<int> parent(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(bfs(i,adj,vis,parent))
            return "Yes";
        }
    }
    return "No";
}
