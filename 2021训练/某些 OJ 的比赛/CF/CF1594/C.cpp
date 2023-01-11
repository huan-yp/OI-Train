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
const int N=3e5+10;
int i,j,k,n,s,t,m;
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		char c;int flag=1;
		cin>>n>>c;
		scanf("%s",ch+1);
		for(i=1;i<=n;i++)
		{
			if(ch[i]!=c)
			flag=0;
		}
		if(flag)
		{
			printf("0\n");
			continue;
		}
		if(ch[n]==c)
		{
			printf("1\n%d\n",n);
			continue;
		}
		int ok=0;
		for(i=1;i<=n;i++)
		{
			int flag=1;
			for(j=1;j*i<=n;j++)
			{
				if(ch[j*i]!=c)
				flag=0;
			}
			if(flag)
			ok=i;
		}
		if(ok)
		{
			printf("1\n%d\n",ok);
			continue;
		}
		printf("%d\n%d %d\n",2,n-1,n);
	}
	return 0;
}

