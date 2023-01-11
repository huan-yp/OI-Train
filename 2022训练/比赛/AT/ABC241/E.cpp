#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
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
int a[N],vis[N],sum[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n),read(k);int now=0,all=0,cnt=0;
	for(i=0;i<n;i++)read(a[i]);
	while(!vis[now]&&cnt<k){
		++cnt,sum[cnt]=sum[cnt-1]+a[now],vis[now]=cnt,now=sum[cnt]%n;
	}
	if(cnt==k){
		printf("%lld\n",sum[cnt]);
		return 0;
	}
	all=sum[cnt]-sum[vis[now]-1],cnt=cnt-vis[now]+1;
	int r=vis[now]-1,ans=sum[r];
	k-=r;ans+=k/cnt*all,k%=cnt,now=ans%n;
	while(k--){
		ans+=a[now];
		now=ans%n;
	}
	printf("%lld\n",ans);
	return 0;
}

