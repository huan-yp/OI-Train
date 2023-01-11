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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N = 1e5+10;
int i,j,k,n,s,t,m;
int pd[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T;read(T);
	while(T--)
	{
		read(n),read(m);
		for(i=1;i<=n;i++)pd[i]=0;
		for(i=1;i<=m;i++)
		{
			int a,b,c;
			read(a),read(b),read(c);
			pd[b]=1;
		}
		int flag=0;
		for(i=1;i<=n;i++)
		if(pd[i]==0)
		flag=i;
		for(i=1;i<=n;i++)
		if(i!=flag)
		printf("%d %d\n",flag,i);
	}
	return 0;
}

