#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m,minu,maxn=2e9,len,ans=2e9;
const int N=2e6+10;
int a[N],b[N],c[N],suf[N],pre[N],sum[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	//sum:前面的 a 的个数。 
	memset(suf,1,sizeof(suf));
	read(n),read(m);
	for(i=1;i<=n;i++)
	read(a[i]),c[i]=a[i];
	for(i=1;i<=n;i++)
	read(b[i]),c[i+n]=b[i];
	
	sort(c+1,c+2*n+1);
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(c+1,c+2*n+1,a[i])-c;
		b[i]=lower_bound(c+1,c+2*n+1,b[i])-c;
		sum[a[i]]++,pre[a[i]]=suf[a[i]]=b[i];
		maxn=min(maxn,max(a[i],b[i]));
		minu=max(minu,min(a[i],b[i]));
	}
	for(i=2;i<=2*n;i++)
	sum[i]+=sum[i-1],pre[i]=max(pre[i-1],pre[i]);
	for(i=2*n;i>=1;i--)
	suf[i]=min(suf[i+1],suf[i]);
	//最小值不小于 i ,最大值不大于 j 
	//maxn:最小值的上界。 
	//minu:最大值的下界。 
	j=minu;
	for(i=1;i<=maxn;i++)
	{
		while(((sum[i-1]+n-sum[j])>m||pre[i-1]>j||suf[j+1]<i)&&j<=2*n)
		j++;
		if(j<=2*n)
		ans=min(ans,c[j]-c[i]);
	}
	cout<<ans;
	return 0;
}


