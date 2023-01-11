#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
const int N=2e5+10;
int i,j,k,n,s,t,m;
int a[N],suf[N],pre[N];
int get(int x,int now=0)
{
	while(x>1<<now)now++;
	return now;
}
int calc(int x,int now=1)
{
	while(now<x)now<<=1;
	return now-x;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n+1;i++)suf[i]=pre[i]=0;
		for(i=1;i<=n;i++)read(a[i]),pre[a[i]]++,suf[a[i]]++;
		for(i=1;i<=n;i++)pre[i]=pre[i-1]+pre[i];
		for(i=n;i>=1;i--)suf[i]=suf[i+1]+suf[i];
		int lst=-1,ans=INF;
		for(i=0;i<=n;i++)
		{
			if(get(pre[i])==get(pre[i+1]))continue;
			lst=get(pre[i]);
			for(j=i+1;j<=n+1;j++)
			cmin(ans,calc(pre[i])+calc(n-pre[i]-suf[j])+calc(suf[j]));
		}
		if(n==1)
		puts("2");
		else
		cout<<ans<<endl;
	}
	return 0;
}

