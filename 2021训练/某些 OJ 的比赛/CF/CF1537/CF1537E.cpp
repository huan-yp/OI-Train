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
const int mod=192781007,base=171;
const int N=1e6+10; 
int i,j,k,n,s,t,m,ans;
int p[N]={1},sum[N]={1},has[N],inv[N]={1};
char ch[N];
struct ms{
	int e1,e2;
	char get(int x)
	{
		if(x<=e1)
		return ch[x];
		return ch[x-e1];
	}
	ms cut(int l)
	{
		ms ret;
		ret.e1=min(e1,l);
		ret.e2=max(0,l-e1);
		return ret;
	}
	friend bool operator ==(ms aa,ms bb)
	{
		int hash1=1ll*has[aa.e1]*p[aa.e2]%mod+has[aa.e2];
		int hash2=1ll*has[bb.e1]*p[bb.e2]%mod+has[bb.e2];
		hash1%=mod,hash2%=mod;
		return (hash1==hash2); 
	}
};
int quick(int aa,int ss)
{
	int ret=1;
	while(ss)
	{
		if(ss&1)
		ret=1ll*ret*aa%mod;
		aa=1ll*aa*aa%mod;
		ss>>=1;
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(i=1;i<N;i++)
	p[i]=1ll*p[i-1]*base%mod,inv[i]=quick(base,mod-2);

	read(n),read(m);
	scanf("%s",ch+1);
	ans=n;
	has[0]=0;
	for(i=1;i<=n;i++)
	{
		has[i]=1ll*has[i-1]*base%mod+ch[i];
		has[i]%=mod;
	}
	for(i=1;i<n;i++)
	{
		int l=1,r=ans+i,opt=0;
		ms a1=(ms){ans,i},a2=(ms){i,ans};
		while(r>=l)//ddcdddc ddcddcd
		{
			int mid=(l+r)/2;
			if((a1.cut(mid))==(a2.cut(mid)))
			l=mid+1,opt=mid;
			else
			r=mid-1;
		}
		if(opt==ans+i)continue;
		if(a1.get(opt+1)<a2.get(opt+1))continue;
		ans=i;
	}
	for(i=1;i<=m;i++)
	printf("%c",ch[(i-1)%ans+1]);
	return 0;
}
//dbcadabcdbca
//dbcadbcadbca


