#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int a[n];
    vector<int> adj_list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        sort(adj_list[x].rbegin(), adj_list[x].rend());
        if (adj_list[x].empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            for (int y : adj_list[x])
            {
                cout << y << " ";
            }

            cout << endl;
        }
    }
    return 0;
}