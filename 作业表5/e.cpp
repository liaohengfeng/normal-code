#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define REP(i,a,b) for(int i(a);i>=(b);--i)
using namespace std;

const int N=2e3 +7,INF=0x3f3f3f3f3f3f;
int n,m,f1(1),f2(1),a[N][N],b[N][N],p[N];
int g[N];int LIS(int *a,int n)
{int len=0; memset(g,0x3f,sizeof g);g[0]=0;rep(i,1,n){if(a[i]>g[len]) g[++len]=a[i];else *lower_bound(g+1,g+len+1,a[i])=a[i];}return len;}

signed main()
{
    freopen("1.in","r",stdin);

    read(n),read(m);
    rep(i,1,n) rep(j,1,m) read(a[i][j]);
    rep(i,1,n) rep(j,1,m) read(b[i][j]),f1&=(b[i][j]!=0),f2&=(a[i][j]==b[i][j]);
    if(f1 && f2) { puts("-1"); exit(0); }


    return 0;
}
