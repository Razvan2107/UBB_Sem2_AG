#include <iostream>
#include <fstream>
using namespace std;
ifstream f("fisier.in");
int n,m1,m2,a[101][101],x[101],nr1,nr2,nr3,b[101][101],viz[101];
void DFS(int x)
{
    int i;
    viz[x]=1;
    for(int i=1;i<=n;i++)
        if(a[x][i]==1 && viz[i]==0)
            DFS(i);
}
bool conex()
{
    int i;
    DFS(1);
    for(int i=1;i<=n;i++)
        if(viz[i]==0)   return 0;
    return 1;
}

int main()
{   f>>n;
    while(f>>m1>>m2)
    {
        a[m1][m2]=1;
        a[m2][m1]=1;
    }

    //cerinta a.
    for(int i=1;i<=n;i++)
    {
        int nr=0;
        for(int j=1;j<=n;j++)
            if(a[i][j]==1)  nr++;
        if(nr==0)
            x[++nr1]=i;
    }
    if(nr1==0)  cout<<"a.Nu exista noduri izolate ale acestui graf!";
    else
    {
        cout<<"a.Nodurile izolate ale acestui graf sunt: ";
        for(int i=1;i<=nr1;i++) cout<<x[i]<<" ";
    }
    cout<<endl;

    //cerinta b.
    for(int j=1;j<=n;j++)
        if(a[1][j]==1) nr2++;
    for(int i=2;i<=n;i++)
    {
        int nr=0;
        for(int j=1;j<=n;j++)
            if(a[i][j]==1) nr++;
        if(nr==nr2) nr3++;
    }
    if(nr3==n-1) cout<<"b.Graful este regular!";
    else cout<<"b.Graful nu este regular!";
    cout<<endl;

    //cerinta c.
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j && a[i][j]==0 &&  a[i][k]==1 && a[k][j]==1)
                    b[i][j]=a[i][k]+a[k][j];
    cout<<"c.Matricea distantelor este:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    //cerinta d.
    if(conex()==1)  cout<<"d.Graful este conex!";
    else    cout<<"d.Graful nu este conex!";
    return 0;
}
