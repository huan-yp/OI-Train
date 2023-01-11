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
const int N=1005;
int i,j,k,n,s,t,m,q,ans;
int mp[N][N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(q);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		ans++;
		ans+=min((n-i),(m-j))*4+((n-i)!=(m-j));
	}
//	cout<<ans<<endl;
	for(int ii=1;ii<=q;ii++)
	{
		int x,y,tmp=0;
		read(x),read(y);
		{
			int l1=0,l2=0,nx=x,ny=y;
			for(i=1;i<=n+m+1;i++)
			{
				nx+=i%2;
				ny+=i%2^1;
				if(nx>n||ny>m||mp[nx][ny])break;
				l2++;
			}
			nx=x,ny=y;
			for(i=1;i<=n+m+1;i++)
			{
				nx-=i%2^1;
				ny-=i%2;
				if(nx<=0||ny<=0||mp[nx][ny])break;
				l1++;
			}
			tmp+=l1*l2+l1+l2;
			l1=0,l2=0,nx=x,ny=y;
			for(i=1;i<=n+m+1;i++)
			{
				nx+=i%2^1;
				ny+=i%2;
				if(nx>n||ny>m||mp[nx][ny])break;
				l2++;
			}
			nx=x,ny=y;
			for(i=1;i<=n+m+1;i++)
			{
				nx-=i%2;
				ny-=i%2^1;
				if(nx<=0||ny<=0||mp[nx][ny])break;
				l1++;
			}
			tmp+=l1*l2+l1+l2;
			tmp++;
		}
		if(mp[x][y])
		ans+=tmp;
		else
		ans-=tmp;
		mp[x][y]^=1;
		cout<<ans<<endl;
		
	}

	return 0;
}

