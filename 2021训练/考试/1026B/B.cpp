#include<bits/stdc++.h>
#define low(x) ((x)&(-x))
using namespace std;
void read(int &x)
{
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
const int N=1<<21;
int c[N],q[N],a[N],b[N],cnt[N];
long long ans[N],sub[N];
int i,j,k,m,n,s,t,threshold,len;
typedef unsigned long long ull;
ull k1, k2;
ull xorShift128Plus()
{
	ull k3 = k1, k4 = k2;
	k1 = k4;
	k3 ^= (k3<<23);
	k2 = k3 ^ k4 ^ (k3>>17) ^ (k4>>26);
	return k2 + k4;
}
void gen(int n, int m, int threshold, ull _k1, ull _k2)
{
	k1 = _k1, k2 =_k2;
	for (int i = 1; i<=1<<n; i++) a[i] = xorShift128Plus() %threshold + 1;
	for (int i = 1; i<=m; i++) q[i] = xorShift128Plus() % (n + 1);
}
void updata(int x,const int &cc)
{
	for(;x>=1;x-=low(x))
	c[x]+=cc;
}
int quert(int x,int ret=0)
{
	for(;x<=len;x+=low(x))
	ret+=c[x];
	return ret;
}
void clear(int l,int r)
{
	for(i=l;i<=r;i++)
	updata(a[i],-1),cnt[a[i]]--;
}
void solve(int l,int r,int level)
{
	int mid=(l+r)/2,mid1=(r+mid+1)/2,mid2=(l+mid)/2;
	if(level<=2)
	{
		ans[1]+=(a[l]>a[l+1])+(a[l+2]>a[l+3]);
		ans[2]+=(a[l]>a[l+2])+(a[l]>a[l+3]);
		ans[2]+=(a[l+1]>a[l+2])+(a[l+1]>a[l+3]);
		sub[1]+=(a[l]==a[l+1])+(a[l+2]==a[l+3]);
		sub[2]+=(a[l]==a[l+2])+(a[l]==a[l+3]);
		sub[2]+=(a[l+1]==a[l+2])+(a[l+1]==a[l+3]);
		for(i=l;i<=mid;i++)
		updata(a[i],1),cnt[a[i]]++;	
		return ;
	}
	solve(mid+1,r,level-1);
	clear(mid+1,mid1);
	solve(l,mid,level-1);
	
	for(i=mid2+1;i<=mid;i++)
	updata(a[i],1),cnt[a[i]]++;
	for(i=mid+1;i<=r;i++)
	ans[level]+=quert(a[i]+1),sub[level]+=cnt[a[i]];
	
}
int main()
{
	cin>>n>>m>>threshold>>k1>>k2;
	gen(n,m,threshold,k1,k2);
	for(i=1;i<=1<<n;i++)b[i]=a[i];
	sort(b+1,b+(1<<n)+1);len=unique(b+1,b+(1<<n)+1)-b-1;
	for(i=1;i<=1<<n;i++)a[i]=lower_bound(b+1,b+len+1,a[i])-b;
	solve(1,1<<n,n);
	long long opt=0;
	for(i=1;i<=m;i++)
	{
		long long sum=0;	
		for(j=1;j<=q[i];j++)
		ans[j]=(1ll<<(n-j))*(1ll<<(j*2-2))-ans[j]-sub[j];
		for(j=1;j<=n;j++)
		sum+=ans[j];
		opt^=(sum*i);
	}	
	cout<<opt<<endl;
	return 0;
}

