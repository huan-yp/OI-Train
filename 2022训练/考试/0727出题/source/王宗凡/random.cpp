#include<cstdio>
#include<cstring>
#include<set>

#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=z;x>=y;x--)

using namespace std;
const int N=1e5+10;

int ans[N],cnt[N],pri[N],mi[N],tem[N],pow[N],inv[N],idx,n,m;
bool is[N],f;
set<int>se;

bool pd(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}

inline int ksm(int x,int y)
{
	int s=1;
	while(y)
	{
		if(y&1) s=1ll*s*x%m;
		x=1ll*x*x%m;
		y>>=1;
	}
	return s;
}

inline void fj(int x,int d)
{
	while(x!=1)
	{
		cnt[mi[x]]+=d;
		if(d==1&&cnt[mi[x]]==1) se.insert(mi[x]);
		else if(d==-1&&cnt[mi[x]]==0) se.erase(mi[x]);
		x/=mi[x];
	}
}

inline int C(int x)//n-1ѡx 
{
	if(x==0) return tem[x]=1;
	if(f)
	{
		return 1ll*pow[n-1]*inv[x]%m*inv[n-1-x]%m;
	}
	if(tem[n-1-x]) return tem[n-1-x];
	fj(n-x,1);
	fj(x,-1);
	int sum=1;
	for(set<int>::iterator i=se.begin();i!=se.end();i++) 
		sum=1ll*sum*ksm(*i,cnt[*i])%m;
	return tem[x]=sum;
}

int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	rep(i,2,N-1)
	{
		if(!is[i]) pri[++idx]=i,mi[i]=i;
		for(int j=1;j<=idx&&pri[j]*i<=N-1;j++)
		{
			int tem=pri[j]*i;
			is[tem]=1;
			mi[tem]=pri[j];
		}
	}
	scanf("%d%d",&n,&m);
	if(m>=n&&pd(m))
	{
		f=1;
		pow[0]=1;
		rep(i,1,n) pow[i]=1ll*pow[i-1]*i%m,inv[i]=ksm(pow[i],m-2);
	}
	rep(i,0,n-1)
	{
		if(C(i)==0)
			ans[++ans[0]]=i+1;
	}
	printf("%d\n",ans[0]);
	rep(i,1,ans[0])
		printf("%d ",ans[i]);
	return 0;
}
