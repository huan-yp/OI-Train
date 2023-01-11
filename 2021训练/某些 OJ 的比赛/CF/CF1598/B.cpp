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
const int N=1e3+10;
int i,j,k,n,s,t,m;
int ok[N][6];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T;
	read(T);
	while(T--)
	{
		read(n);int flag=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=5;j++)
			read(ok[i][j]);
		}
		for(i=1;i<=5;i++)
		{
			for(j=i+1;j<=5;j++)
			{
				int cnt0=0,cnt1=0,cnt2=0;
				for(k=1;k<=n;k++)
				{
					if(ok[k][i]&&ok[k][j])	
					{
						cnt2++;
						continue;
					}
					if(ok[k][i])
					cnt1++;
					if(ok[k][j])
					cnt0++;
				}
				if(cnt1+cnt0+cnt2==n&&cnt1<=n/2&&cnt0<=n/2)
				flag=1;
			}
		}
		if(flag)
		puts("YES");
		else
		puts("NO");
	}

	return 0;
}

