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
int i,j,k,n,s,t,m;
struct building{
	int val,rk;
	friend bool operator <(building a,building b)
	{
		return a.val>b.val;
	}
}a[N];
int pos[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);
	while(tot--)
	{
		read(n);int ans=0;
		for(i=1;i<=n;i++)read(a[i].val),a[i].rk=i;
		sort(a+1,a+n+1);
		pos[0]=N/2;
		for(i=1;i<=n;i+=2)
		{
			pos[a[i].rk]=pos[0]+i/2+1;
			if(i+1<=n)
			pos[a[i+1].rk]=pos[0]-i/2-1;
		}
		for(i=1;i<=n;i++)
		ans+=2*a[i].val*abs(pos[a[i].rk]-pos[0]);
		cout<<ans<<endl;
		for(i=0;i<=n;i++)
		printf("%lld ",pos[i]);
		cout<<endl;
	}
	return 0;
}

