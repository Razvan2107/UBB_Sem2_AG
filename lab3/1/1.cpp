#include <iostream>
#include<set>
#include<queue>

#define infinit 100000000
using namespace std;

struct pereche
{
    int varf, distanta;
    bool operator<(const pereche rhs) const
    {
        return distanta > rhs.distanta;
    }
};

set<pair<int, int>> vecini[101];
priority_queue<pereche> q;
int d[101];

void dijkstra(int start, int noduri)
{
    q.push({ start,0 });
    d[start] = 0;
    while (!q.empty())
    {
        int nod = q.top().varf;
        q.pop();
        for (auto j : vecini[nod])
        {
            if (d[j.first] > d[nod] + j.second) {
                d[j.first] = d[nod] + j.second;
                q.push({ j.first,d[j.first] });
            }
        }

    }

}

int main()
{
    int n, m, start, a, b, c;
    cin >> n >> m >> start;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        vecini[a].insert({ b,c });
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] = infinit;
    }
    dijkstra(start, n);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != infinit) {
            cout << d[i] << " ";
        }
        else
        {
            cout << -1 << ' ';
        }
    }
    return 0;
}