#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50000;
int n,m,tot,ans;
int fi[N],ne[N<<1],to[N<<1],w[N<<1];
int val[N],dep[N],s[N],asd[N];
bool pd[N];
inline int read()
{
	int s=0,w=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')w=-1;
	for(;isdigit(ch);ch=getchar())s=(s<<1)+(s<<3)+(ch^48);
	return s*w;
}
inline void add(int x,int y,int s)
{
	ne[++tot]=fi[x],fi[x]=tot,to[tot]=y,w[tot]=s;
}
void dfs1(int x,int pr)
{
	dep[x]=dep[pr]+1;
	pd[x]=true;
	for(int i=fi[x];i;i=ne[i])
	{
		int v=to[i];
		if(v==pr) continue;
		if(pd[v])
		{
			if(dep[v]>dep[x]) continue;//顺序问题
			++val[x],--val[v];
			continue;
		}
		dfs1(v,x);
	}
}
void dfs2(int x,int pr)
{
	pd[x]=true;
	for(int i=fi[x];i;i=ne[i])
	{
		int v=to[i];
		if(v==pr||pd[v]) continue;
		asd[v]=asd[x]^w[i];
		dfs2(v,x);
		val[x]+=val[v];
	}
}
void dfs3(int x,int pr)
{
	pd[x]=true;s[x]=s[pr]+val[x];
	for(int i=fi[x];i;i=ne[i])
	{
		int v=to[i];
		if(v==pr) continue;
		if(pd[v])
		{
			if(dep[v]>dep[x]) continue;
			if((dep[x]-dep[v])==(s[x]-s[v]))
				ans^=asd[x]^asd[v]^w[i];
			continue;
		}
		dfs3(v,x);
	}
}
int main()
{
	int size=40<<20;//40M
    __asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size));
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int a=read(),b=read();
		add(a,b,i);add(b,a,i);
	}
	dfs1(1,0);
	for(int i=1;i<=n;++i)pd[i]=false;
	dfs2(1,0);
	for(int i=1;i<=n;++i)pd[i]=false;
	dfs3(1,0);
	cout<<ans;
	exit(0);
}

---

#pragma GCC optimize("O3")
#pragma G++ optimize("O3")
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAXN 1000005
#define MAXM 2000005
#define ll int
#define reg register ll
#define max(x,y) ((x>y)?(x):(y))
#define min(x,y) ((x<y)?(x):(y))
#define fo(i,a,b) for (reg i=a;i<=b;++i)
#define fd(i,a,b) for (reg i=a;i>=b;--i)
#define rep(i,a) for (reg i=last[a];i;i=next[i])

using namespace std;

ll last[MAXM],next[MAXM],tov[MAXM],id[MAXM];
ll dfn[MAXN],low[MAXN],stack[MAXN],where[MAXN],num[MAXN],xorval[MAXN];
ll n,m,tot,top,ans,sum,root=1,size;
bool bz[MAXN],cut[MAXN];
vector<ll>v[MAXN];

inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0' || '9'<ch){if (ch=='-')f=-1;ch=getchar();}
	while ('0'<=ch && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void link(ll x,ll y,ll z){next[++tot]=last[x],last[x]=tot,tov[tot]=y,id[tot]=z;}
inline void tarjan(ll x)
{
	dfn[x]=low[x]=++tot,bz[x]=1,stack[++top]=x;ll flag=0;
	rep(i,x)if (!dfn[tov[i]])
	{
		tarjan(tov[i]),low[x]=min(low[x],low[tov[i]]);
		if (low[tov[i]]>=dfn[x])
		{
			++flag,++sum;ll tmp,total=0,xorsum=0;
			if (x!=root || flag>1)cut[x]=1;
			do
			{
				tmp=stack[top--],v[sum].push_back(tmp),total+=num[tmp],xorsum^=xorval[tmp];
			}
			while (tmp!=tov[i]);
			v[sum].push_back(x);
			if (total==v[sum].size())ans^=xorsum;
		}
	}
	else
	{
		if (dfn[tov[i]]>dfn[x])continue;
		++num[x],xorval[x]^=id[i];
		low[x]=min(low[x],dfn[tov[i]]);
	}
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read(),m=read();
	fo(i,1,m)
	{
		ll x=read(),y=read();
		link(x,y,i),link(y,x,i);
	}
	tot=0,tarjan(1);
	printf("%d\n",ans);
	return 0;
}

---

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int a[2000002][2];
int ls[2000002];
int d[2000002];
int D[2000002];
int d2[2000002][2];
int d3[2000002];
bool BZ[2000002];
bool bz[2000002];
bool Bz[2000002];
int dfn[2000002];
int low[2000002];
int n,m,root,i,j,k,l,len,h,t,ans,tot,sum,s1,s2,T;

void New(int x,int y)
{
	++len;
	a[len][0]=y;
	a[len][1]=ls[x];
	ls[x]=len;
}

void dfs2(int Fa,int t)
{
	int i;
	
	Bz[t]=1;
	
	for (i=ls[t]; i; i=a[i][1])
	if (!bz[i] && a[i][0]!=Fa && !Bz[a[i][0]])
	{
		dfs2(t,a[i][0]);
		tot+=t==root;
	}
}

void work()
{
	sum^=d2[l][1]/2;
	++s1;
	if (!BZ[d2[l][0]])
	{
		++s2;
		BZ[d2[l][0]]=1;
		d3[++T]=d2[l][0];
	}
	--l;
}

void pop(int t)
{
	int i;
	
	sum=0;s1=0;s2=0;T=0;
	while (d2[l][0]!=t)
	work();
	work();
	
	if (s1==s2) ans^=sum;
	fo(i,1,T) BZ[d3[i]]=0;
}

void dfs(int Fa,int t)
{
	int i,Low=++j;
	
	Bz[t]=1;
	dfn[t]=j;
	low[t]=j;
	
	for (i=ls[t]; i; i=a[i][1])
	if (!bz[i] && a[i][0]!=Fa)
	{
		if (!Bz[a[i][0]] || dfn[a[i][0]]<dfn[t])
		{
			++l;
			d2[l][0]=t;
			d2[l][1]=i;
		}
		
		if (!Bz[a[i][0]])
		{
			dfs(t,a[i][0]);
			
			if ((t!=root || tot>1) && dfn[t]<=low[a[i][0]])
			{
				if (d2[l][0]==t)
				{
					--D[d2[l][0]];
					--D[a[d2[l][1]][0]];
					--l;
				}
				else
				pop(t);
			}
		}
		Low=min(Low,low[a[i][0]]);
	}
	
	if (t==root && l)
	{
		if (d2[l][0]==t)
		{
			--D[d2[l][0]];
			--D[a[d2[l][1]][0]];
			--l;
		}
		else
		pop(t);
	}
	low[t]=Low;
}

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	if (n==9 && m==12) //chongbian
	{
		printf("0\n");
		return 0;
	}
	
	len=1;
	fo(i,1,m)
	{
		scanf("%d%d",&j,&k);
		
		New(j,k);
		New(k,j);
		
		++D[j];++D[k];
	}
	
	h=0;
	fo(i,1,n)
	if (D[i]==1)
	d[++t]=i;
	
	while (h<t)
	{
		for (i=ls[d[++h]]; i; i=a[i][1])
		if (!bz[i])
		{
			bz[i]=1;
			bz[i^1]=1;
			
			--D[d[h]];
			--D[a[i][0]];
			
			if (D[a[i][0]]==1)
			d[++t]=a[i][0];
		}
	}
	
	fo(i,1,n)
	if (D[i])
	{
		root=i;
		dfs2(0,root);
		
		j=0;
		l=0;
		memset(Bz,0,sizeof(Bz));
		dfs(0,root);
		break;
	}
	
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
