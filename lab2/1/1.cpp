#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream f("graf.in");
int main()
{	int n,s,x,y;
	f >> n;
	vector<vector<int>> G(n + 1);
	while (f >> x >> y)
		G[x].emplace_back(y);
	f.close();
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
		cout << i << ' ' << d[i] - 1 << '\n';
    return 0;
}