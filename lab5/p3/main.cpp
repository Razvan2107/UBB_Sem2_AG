#include <iostream>
using namespace std;
int a[101][101], l[201], n, m, v1, v2, p=0;

void Euler(int k)
{
	for(int i=0;i<n;i++)
		if (a[k][i])
		{
			a[k][i] = a[i][k] = 0;
			Euler(i);
		}
	l[++p] = k;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;
		a[v1][v2] = a[v2][v1] = 1;
	}
	Euler(0);
	for (int i = 1; i < p; i++)
		cout << l[i] << " ";
	return 0;
}
/*
5 6
0 1
0 2
1 2
2 3
2 4
3 4

0 2 4 3 2 1
*/