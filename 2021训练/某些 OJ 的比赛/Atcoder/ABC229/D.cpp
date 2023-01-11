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
const int N=3e5+10;
int i,j,k,n,s,t,m,ans;
int sum[N];
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s",ch+1);read(k);
	n=strlen(ch+1);
	for(i=1;i<=n;i++)
	sum[i]=sum[i-1]+(ch[i]=='.');
	for(i=1;i<=n;i++)
	{
		int l=i,r=n,opt=0;
		while(r>=l)
		{
			int mid=(l+r)/2;
			if(sum[mid]-sum[i-1]<=k)
			l=mid+1,opt=mid-i+1;
			else r=mid-1;
		}
		cmax(ans,opt);
	}
	cout<<ans<<endl;
	return 0;
}

