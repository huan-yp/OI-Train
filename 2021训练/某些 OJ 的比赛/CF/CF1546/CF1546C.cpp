#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define low(x) (x)&(-x)
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
const int N=5e5+10;
int i,j,k,n,s,t,m;
int a[N],cnt[N][2][2];
struct num{
	int rk,val;
	friend bool operator <(num a,num b)
	{
		return a.val<b.val;
	}
}b[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int flag=1;
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]),cnt[a[i]][0][i%2]++;
		
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		cnt[a[i]][1][i%2]++;
		
		for(i=1;i<=n;i++)
		{
			if(cnt[a[i]][0][0]!=cnt[a[i]][1][0]||cnt[a[i]][0][1]!=cnt[a[i]][1][1])
			flag=0;
			cnt[a[i]][0][1]=0,cnt[a[i]][1][1]=0;
			cnt[a[i]][0][0]=0,cnt[a[i]][1][0]=0;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}

