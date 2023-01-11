#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1e6+10;
int i,j,k,n,s,t,m,e,ans;
int a[N],pd[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);
	for(i=2;i<N;i++)
	for(j=i*2;j<N;j+=i)
	pd[j]=1;
	
	while(tot--)
	{
		read(n),read(e);ans=0;
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			if(a[i]==1)a[i]=0;
			else
			if(pd[a[i]]==0)a[i]=1;
			else
			if(pd[a[i]]==1)a[i]=2;
		}
		for(i=1;i<=e;i++)
		{
			int lst=0,llst=0,have=0;
			for(j=i;j<=n;j+=e)
			{
				if(a[j]==1)
				{
					if(have)ans+=llst*lst+llst+lst;
					have=1;
					llst=lst,lst=0;
				}
				if(a[j]==0)
				lst++;
				if(a[j]==2)
				{
					if(have)ans+=llst*lst+llst+lst;
					have=lst=llst=0;
				}
			}
			if(have)
			ans+=llst*lst+llst+lst;
		}
		cout<<ans<<endl;
	}

	return 0;
}

