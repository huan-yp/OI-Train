#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1e5+10;
int i,j,k,n,s,t,m;
int p[N],ok[N];
void solve()
{
	for(i=1;i<N;i++)
	ok[i]=1;
	
	for(i=2;i<N;i++)
	{
		int pd=1;
		for(j=1;j*i<N;j++)
		if(p[j*i])
		pd=0;
		
		for(j=1;j*i<N;j++)
		ok[j*i]&=pd;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	{
		int x;
		read(x),p[x]=1;
	}
	solve();
	for(i=1;i<=m;i++)
	if(ok[i])s++;
	
	printf("%d\n",s);
	for(i=1;i<=m;i++)
	{
		if(ok[i])
		printf("%d\n",i);
	}
	return 0;
}

