#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> edges{{1, 2}, {0, 3}, {2, 3}};

    int n = 4;
    int m = 3;
    vector<vector<int>> vect(n);


    for (int i = 0; i < m; i++)
    {

        int v = edges[i][0];
        int u = edges[i][1];

        vect[v].push_back(u);
        vect[u].push_back(v);
    }

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    // vector<vector<int>> adj(n);

    // for (int i = 0; i < n; i++)
    // {
    //     adj[i].push_back(i);
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         adj[i].push_back(ans[i][j]);
    //     }
    // }

    return 0;
}
