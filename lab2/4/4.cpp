#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{	int n, m, s;
	cin >> n >> m;
	vector<vector<int>> G(n + 1);
	while (m--) {
		int x, y;
		cin >> x >> y;
		G[x].emplace_back(y);
	}
	cin >> s;
	vector<int> d(n + 1);
	queue<int> Q;
	d[s] = 1;
	Q.emplace(s);
	while (!Q.empty()) 
	{
		int node = Q.front();
		Q.pop();
		for (auto x : G[node])
			if (!d[x]) 
			{
				d[x] = d[node] + 1;
				Q.emplace(x);
			}
	}
	for (int i = 1; i <= n; ++i)
		if (d[i])
			cout << i << ' ' << d[i] - 1 << '\n';
	return 0;
}
/*
5 7
2 5
1 2
2 3
2 5
3 4
4 2
4 5
3
*/