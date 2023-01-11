#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
const int N=300005;
int i,j,k,n,s,t,m,ans,now;
int c[N],b[N],cnt[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=n;i++)
	read(c[i]),b[i]=c[i];
	
	sort(b+1,b+n+1),m=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++)
	c[i]=lower_bound(b+1,b+m+1,c[i])-b-1;
	
	for(i=1;i<=k;i++)
	{
		if(cnt[c[i]]==0)now++;
		cnt[c[i]]++;
	}
	ans=now;
	for(i=k+1;i<=n;i++)
	{
		if(cnt[c[i-k]]==1)now--;
		cnt[c[i-k]]--;
		if(cnt[c[i]]==0)now++;
		cnt[c[i]]++;
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}

