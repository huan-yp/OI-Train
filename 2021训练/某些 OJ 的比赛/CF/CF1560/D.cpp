#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
int i,j,k,n,s,t,m;
int p[65]={1};
int change(int x,int y)
{
	int g1[65],g2[65],cnt1=0,cnt2=0,ans=0,now=1;
	while(x){
		g1[++cnt1]=x%10;
		x/=10;
	}
	while(y){
		g2[++cnt2]=y%10;
		y/=10;
	}
	for(i=1;i<=cnt1/2;i++)swap(g1[i],g1[cnt1-i+1]);
	for(i=1;i<=cnt2/2;i++)swap(g2[i],g2[cnt2-i+1]);
	
	for(i=1;i<=cnt2;i++)
	{
		while(g1[now]!=g2[i]&&now<=cnt1)
		now++;
		if(now>cnt1)break;
		ans++,now++;
	}
	return cnt1+cnt2-ans*2;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	for(i=1;i<=60;i++)
	p[i]=p[i-1]*2;
	while(t--)
	{
		int ans=INF;
		read(n);
		for(j=0;j<=60;j++)
		cmin(ans,change(n,p[j]));
		
		printf("%lld\n",ans);
	}

	return 0;
}

