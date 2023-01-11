#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=2e5+10,mod=998244353;
int i,j,k,n,s,t,m,ans,now=1,tag=1;
int a[N],b[N],cnt[N],f[N],inv[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=ret*a%mod;
		s>>=1;a=a*a%mod;
	}
	return ret;
}
struct SGT{
	int a[N<<3];
	void push_up(int rt){
		a[rt]=(a[rt<<1]+a[rt<<1|1])%mod;
	}
	void build(int l,int r,int rt){
		if(l==r){
			if(cnt[l]==0)a[rt]=0;
			else a[rt]=f[n-1]*now%mod*cnt[l]%mod;
			return ;
		}	
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void updata(int l,int r,int rt,int x,int c){
		if(l==r){
			a[rt]=c;
			return ;
		}
		int mid=(l+r)/2;
		if(x<=mid)updata(l,mid,rt<<1,x,c);
		else updata(mid+1,r,rt<<1|1,x,c);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y){
		if(x>y)return 0;
		if(x<=l&&y>=r)return a[rt];
		int ret=0,mid=l+r>>1;
		if(x<=mid)ret+=quert(l,mid,rt<<1,x,y);
		if(y>mid)ret+=quert(mid+1,r,rt<<1|1,x,y),ret%=mod;
		return ret;
	}
}T;
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n),read(m);
	f[0]=inv[0]=1;
	for(i=1;i<N;i++)f[i]=f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=1;i<=n;i++)read(a[i]),cnt[a[i]]++;
	for(i=1;i<=m;i++)read(b[i]);
	for(i=1;i<N;i++){
		now*=inv[cnt[i]];
		now%=mod;
	}
	T.build(1,N-1,1);
	for(i=1;i<=m;i++){
		int val=T.quert(1,N-1,1,1,b[i]-1);
		ans+=T.quert(1,N-1,1,1,b[i]-1)*tag%mod;
		ans%=mod;
		if(cnt[b[i]]==0)break;
		tag=tag*quick(n-i,mod-2)%mod*cnt[b[i]]%mod;
		now=now*cnt[b[i]]%mod;
		if(i==n){
			ans+=(m>n),ans%=mod;
		}
		cnt[b[i]]--;
		T.updata(1,N-1,1,b[i],f[n-i-1]*quick(tag,mod-2)%mod*now%mod*cnt[b[i]]%mod);
	}
	cout<<ans%mod<<endl;
	return 0;
}

