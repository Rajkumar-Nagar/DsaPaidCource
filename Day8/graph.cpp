#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph
{

public:
    unordered_map<int, list<int>> gp;

    void addedge(int u, int v, bool direction)
    {

        gp[u].push_back(v);

        //    direction ->0 undirected graph
        //    direction ->1 directed graph

        if (direction == 0)
        {
            gp[v].push_back(u);
        }
    }

    void pirintgraph()
    {
        for (auto i : gp)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
        }
    };
};
int main()
{

    int n;
    cout << "inter the no of nodes  ";
    cin >> n;

    int m;
    cout << "inter the no of edges";
    cin >> m;

    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);
    }

    g.pirintgraph();
    return 0;
}
