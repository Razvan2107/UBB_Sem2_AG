#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
//ifstream cin("labirint_1.txt");
ifstream cin("labirint_2.txt");
int main()
{
	vector<pair<int, int>> dd = { {-1,0},{0,1},{0,-1},{1,0} };
	vector<string> v;
	string s;
	while (getline(cin, s))
		v.emplace_back(s)/*, cerr << s << '\n'*/;
	int n = v.size(), m = v[0].size();
	pair<int, int> start, finish;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (v[i][j] == 'S')
				start = { i,j };
			else if (v[i][j] == 'F')
				finish = { i,j };
	vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m));
	queue<pair<int, int>> Q;
	Q.emplace(start);
	p[start.first][start.second] = { -1,-1 };
	while (!Q.empty()) {
		auto [y, x] = Q.front();
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int yy = y + dd[i].first, xx = x + dd[i].second;
			if (yy >= 0 && xx >= 0 && yy < n && xx < m && (v[yy][xx] == ' ' || v[yy][xx] == 'F') && p[yy][xx] == make_pair(0, 0)) {
				p[yy][xx] = { y,x };
				Q.emplace(yy, xx);
			}
		}
	}
	//cerr << p[finish.first][finish.second].first << ' ' << p[finish.first][finish.second].second << '\n';
	for (auto [y, x] = finish; y != -1;) {
		//cerr << y << ' ' << x << '\n';
		v[y][x] = '*';
		auto [yy, xx] = p[y][x];
		y = yy, x = xx;
	}
	v[start.first][start.second] = 'S';
	v[finish.first][finish.second] = 'F';
	for (int i = 0; i < n; ++i)
		cout << v[i] << '\n';

	return 0;
}