#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf.in");
int main()
{
    int n, m1, m2, a[101][101];
    f >> n;
    while (f >> m1 >> m2)
    {
        a[m1][m2] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] == 0)
                    a[i][j] = (a[i][k] & a[k][j]); //&&
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    f.close();
    return 0;
}