#include <iostream>
#include <vector>
using namespace std;
int main()
{	int n, m, s;
	cin >> n >> m;
	vector<vector<int>> G(n + 1, vector<int>(n + 1));
	vector<int> seen(n + 1);
	while (m--) 
	{
		int x, y;
		cin >> x >> y;
		G[x].emplace_back(y);
	}
	auto dfs = [&](auto& self, int node) -> void 
	{
		seen[node] = 1;
		for (auto x : G[node])
			if (!seen[x])
				self(self, x);
	};
	cin >> s;
	dfs(dfs, s);
	for (int i = 1; i <= n; ++i)
		if (seen[i])
			cout << i << ' ';
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
*/