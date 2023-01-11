#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=2e5+10;
int i,j,k,n,s,t,m,flag;
int fa[N],cnt[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		cnt[x]++,cnt[y]++;
		if(find(x)==find(y))flag=1;
		fa[find(x)]=find(y);
	}
	for(i=1;i<=n;i++)
	if(cnt[i]>2)flag=1;
	
	if(flag)
	puts("No");
	else
	puts("Yes");
	return 0;
}

