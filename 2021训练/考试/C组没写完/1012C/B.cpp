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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e5+10;
int i,j,k,n,s,t,m;
int nxt[N],a[N];
char ch[N];
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y)
{
	return x/gcd(x,y)*y;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int ans=1;read(m);
	for(i=1;i<=m;i++)read(a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%s",ch+1);
		j=nxt[0]=-1;n=strlen(ch+1);
		for(k=1;k<=n;k++)
		{
			while(ch[j+1]!=ch[k]&&j!=-1)
			j=nxt[j];
			nxt[k]=++j;
		}
		int minu=n,len=n-nxt[n];
		if(n%len==0)minu=len;
		ans=lcm(ans,minu/gcd(minu,a[i]));
	}
	cout<<ans<<endl;
	return 0;
}

