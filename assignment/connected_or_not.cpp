#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];
    memset(adj_mat, 0, sizeof(adj_mat));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 1;
            }
        }
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
    }

    int x;
    cin >> x;

    while (x--)
    {
        int c, d;
        cin >> c >> d;
        if (adj_mat[c][d] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}