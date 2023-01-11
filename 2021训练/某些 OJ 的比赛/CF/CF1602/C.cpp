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
int cnt[32];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T=1;read(T);
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		read(n);
		for(i=1;i<=n;i++)
		{
			int x;
			read(x);
			for(j=0;j<=30;j++)
			cnt[j]+=(1<<j&x)?1:0;
		}
		for(i=1;i<=n;i++)
		{
			int flag=1;
			for(j=0;j<=30;j++)
			if(cnt[j]%i)flag=0;
			if(flag)
			printf("%d ",i);
		}
		cout<<endl;
	}
	return 0;
}

