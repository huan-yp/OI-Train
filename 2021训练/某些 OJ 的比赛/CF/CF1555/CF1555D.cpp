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
const int N=2e5+10;
int i,j,k,n,s,t,m;
int sum[10][N];
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	scanf("%s",ch+1);
	for(i=1;i<=n;i++)
	{
		if(i%3==1)
		{
			sum[1][i]=sum[1][i-1]+(ch[i]!='a'); //abc
			sum[2][i]=sum[2][i-1]+(ch[i]!='a'); //acb
			sum[3][i]=sum[3][i-1]+(ch[i]!='b'); //bac
			sum[4][i]=sum[4][i-1]+(ch[i]!='b'); //bca
			sum[5][i]=sum[5][i-1]+(ch[i]!='c'); //cab
			sum[6][i]=sum[6][i-1]+(ch[i]!='c'); //cba
		}
		if(i%3==2)
		{
			sum[1][i]=sum[1][i-1]+(ch[i]!='b'); //abc
			sum[2][i]=sum[2][i-1]+(ch[i]!='c'); //acb
			sum[3][i]=sum[3][i-1]+(ch[i]!='a'); //bac
			sum[4][i]=sum[4][i-1]+(ch[i]!='c'); //bca
			sum[5][i]=sum[5][i-1]+(ch[i]!='a'); //cab
			sum[6][i]=sum[6][i-1]+(ch[i]!='b'); //cba
		}
		if(i%3==0)
		{
			sum[1][i]=sum[1][i-1]+(ch[i]!='c'); //abc
			sum[2][i]=sum[2][i-1]+(ch[i]!='b'); //acb
			sum[3][i]=sum[3][i-1]+(ch[i]!='c'); //bac
			sum[4][i]=sum[4][i-1]+(ch[i]!='a'); //bca
			sum[5][i]=sum[5][i-1]+(ch[i]!='b'); //cab
			sum[6][i]=sum[6][i-1]+(ch[i]!='a'); //cba
		}
	}
	for(i=1;i<=m;i++)
	{
		int ans=INF,l,r;
		read(l),read(r);
		for(j=1;j<=6;j++)
		cmin(ans,sum[j][r]-sum[j][l-1]);
		printf("%d\n",ans);
	}
	return 0;
}

