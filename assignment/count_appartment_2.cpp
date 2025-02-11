#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.' && !vis[i][j];
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int roomSize = 1; 

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj))
        {
            roomSize += dfs(ci, cj); 
        }
    }
    return roomSize;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    vector<int> roomSizes; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                int size = dfs(i, j);
                roomSizes.push_back(size);
            }
        }
    }

    if (roomSizes.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        sort(roomSizes.begin(), roomSizes.end());

        for (int size : roomSizes)
        {
            cout << size << " ";
        }
        cout << endl;
    }

    return 0;
}
