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
const int N=1e6+10;
int i,j,k,n,s,t,m;
string ch[N];
int sum[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
//	int T;read(T);
//	while(T--)
	{
		read(n),read(m);
		for(i=1;i<=n;i++)
		ch[i]+=' ';
		for(i=1;i<=n;i++)
		{
			string tmp;
			cin>>tmp;
			ch[i]+=tmp;
		}
		for(i=1;i<=m;i++)
		{
			int flag=0,pd=0;
			for(j=2;j<=n;j++)
			if(ch[j-1][i]=='X'&&ch[j][i-1]=='X')pd=1;
			sum[i]=sum[i-1]+pd;
		}
		//string 访问无效内存会出问题 
		int q;read(q);
		for(i=1;i<=q;i++)
		{
			int x,y;
			read(x),read(y);
			if(sum[x]-sum[y])
			printf("NO\n");
			else
			printf("YES\n");
		}
	}
	return 0;
}

