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
const int N=2e3+10;
int i,j,k,n,s,t,m;
char ch[N],ans[N];
int a[N],b[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(k),read(s);m=0;
		scanf("%s",ch+1);
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
			if(ch[i]!=ch[i-1])++m;
			if(ch[i]=='a')a[m]--;
			else a[m]++;
		}
		s--;
		for(i=m;i>=1;i--)
		{
			if(a[i]<0){b[i]=a[i];continue;}
			b[i]=s%(a[i]*k+1);s/=(a[i]*k+1);
		}
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=abs(b[i]);j++)	
			putchar((b[i]<0?'a':'b'));
		}
		cout<<endl;
	}
	return 0;
}

