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
char a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T=1;
	read(T);
	while(T--)
	{
		read(n);int ans=1e9;
		scanf("%s",a+1);
		for(k='a';k<='z';k++)
		{
			int flag=1,cnt=0,now=n;
			
			for(i=1;i<=n&&i<now;i++)
			{
				if(a[i]==a[now])
				now--;
				else
				{
					if(a[i]==k)
					{
						cnt++;
						continue;
					}
					while(a[now]==k&&now>i)
					{
						now--;
						cnt++;
						continue;
					}
					if(a[now]!=a[i])flag=0;
					now--;
				}
			}
			if(flag)cmin(ans,cnt);
		}
		if(ans!=1e9)
		cout<<ans<<endl;
		else
		cout<<-1<<endl;
	}

	return 0;
}

