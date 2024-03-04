#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Nod 
{
    int parinte;
    int copii;
}vector_tati[100000];

int n;
vector <int> rez;
priority_queue <int> Q;

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> vector_tati[i].parinte;
        vector_tati[vector_tati[i].parinte].copii++;
    }
    bool bun;
    for (int i = 0; i < n; i++) 
    {
        bun = true;
        for (int j = 0; j < n; j++) 
        {
            if (i == vector_tati[j].parinte)
                bun = false;
        }
        if (bun)
            Q.push(-i);
    }
    while (!Q.empty()) 
    {
        int frunza = -Q.top();
        Q.pop();
        vector_tati[vector_tati[frunza].parinte].copii--;
        rez.push_back(vector_tati[frunza].parinte);
        if (vector_tati[vector_tati[frunza].parinte].parinte != -1 && vector_tati[vector_tati[frunza].parinte].copii == 0)
            Q.push(-vector_tati[frunza].parinte);
    }
    cout << rez.size() << endl;
    for (int i = 0; i < rez.size(); i++)
        cout << rez[i] << ' ';
    return 0;
}
/*
7
-1 0 1 1 2 0 5

6
1 2 1 0 5 0
*/