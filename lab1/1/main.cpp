#include <iostream>
#include <fstream>
using namespace std;
ifstream f("fisier.in");
int main()
{   int n,m1,m2,a[101][101]={0};
    f>>n;
    while(f>>m1>>m2)
    {
        a[m1][m2]=1;
        a[m2][m1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    f.close();
    return 0;
}
