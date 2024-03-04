#include <iostream>
using namespace std;

struct muchie 
{
    int i;
    int j;
    int cost;
};

int n, m, t[501], l[501], r[501], nr=0;

muchie x[100000];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
        cin >> x[i].i >> x[i].j >> x[i].cost;

    //sortare tablou x[] după campul cost
    for(int i=0;i<m-1;i++)
        for(int j=i+1;j<m;j++)
            if (x[j].cost < x[i].cost)
            {
                int a = x[i].i, b = x[i].j, c = x[i].cost;
                x[i].i = x[j].i, x[i].j = x[j].j, x[i].cost = x[j].cost;
                x[j].i = a, x[j].j = b, x[j].cost = c;
            }

    //initializare reprezentanti
    for (int i = 1; i <= n; ++i)
        t[i] = i;

    //determinare Arborele Partial de cost Minim
    int s = 0;
    for (int i = 0; i < m; i++)
        // extremitatile fac parte din subarbori diferiti
        if (t[x[i].i] != t[x[i].j]) 
        {
            s += x[i].cost;
            //reunim subarborii
            int ai = t[x[i].i], aj = t[x[i].j];
            for (int j = 1; j <= n; ++j)
                if (t[j] == aj)
                    t[j] = ai;
            l[++nr] = x[i].i, r[nr] = x[i].j;
        }

    //afisam suma
    cout << s << "\n";

    //afisez arborele partial de cost minim
    cout << nr << "\n";
    for (int i = 1; i <= nr; i++)
        cout << l[i] << " " << r[i] << "\n";
    return 0;
}