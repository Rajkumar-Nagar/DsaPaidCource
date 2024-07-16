#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <list>

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}

void dfs(int node, int parent, vector<int> &disc, unordered_map<int, bool> &vis, vector<int> &low, unordered_map<int, list<int>> &adj, vector<int> &ap, int &timer)
{

    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adj[node])
    {

        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, disc, vis, low, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);

            // check ap or not
            if (low[nbr] >=disc[node]&& parent!=-1){
                ap[node]=1;
            }
            child++;
        }
        else{
            // backedge
            low[node]=min(low[node],disc[nbr]);
        }
    }

    if(parent==-1&& child>1){
        ap[node]=1;
    }
}

int main()
{

    int n = 5;
    int e = 5;
    vector<pair<int, int>> edegs;
    unordered_map<int, list<int>> adj;

    edegs.push_back(make_pair(0, 3));
    edegs.push_back(make_pair(3, 4));
    edegs.push_back(make_pair(0, 4));
    edegs.push_back(make_pair(0, 1));
    edegs.push_back(make_pair(1, 2));

    for (int i = 0; i < edegs.size(); i++)
    {
        int v = edegs[i].first;
        int u = edegs[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;

    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }
    // DFS CALL

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, disc, vis, low, adj, ap, timer);
        }
    }

    cout << "aritculation points are as follows" << endl;

    for (int i = 0; i < n; i++)
    {
        if (ap[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
