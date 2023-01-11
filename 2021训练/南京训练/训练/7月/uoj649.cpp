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
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		
		read(n),read(m),read(k);
		int opt=-n*n;
		if(n<m||(k==0&&n%m!=0))
		{
			printf("-1\n");
			continue;
		}
		if(k==0)
		{
			printf("0\n");
			continue;
		}
		n-=m;
		s=n/k;
		//i*(i+1)/2<=s
		int l=0,r=m,ans=0;
		while(r>=l)
		{
			int mid=(l+r)/2;
			if(mid*(mid+1)/2<=s)
			ans=mid,l=mid+1;
			else
			r=mid-1;
		}
		n-=ans*(ans+1)/2*k;
		if(ans==m)
		{
			for(i=1;i<=ans;i++)
			{
				int cnt=i*k+n/m+(i<=n%m)+1;
				opt+=m*cnt*cnt;
			}
		}
		else
		{
			for(i=ans+2;i<=m;i++)
			opt+=1*1*m;
			for(i=0;i<=ans;i++)
			{
				int cnt=k*i+1;
				cnt+=n/(ans+1);
				cnt+=(i<n%(ans+1));
				opt+=cnt*cnt*m;
			}
		}
		cout<<opt<<endl;
	}
	return 0;
}

