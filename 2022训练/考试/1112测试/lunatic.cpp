#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=1e5+10;
int n,m,s;
int val[N],b[N];
struct seg{
	int l,r;
	bool operator <(const seg &a) const{
		if(a.r!=r)return r<a.r;
		return l>a.l;
	}
}a[N],ta[N];
void ___solve(){
	int i,j,k,maxn=0,ans=0;
	read(n),read(k);
	for(i=1;i<=n;i++)read(a[i].l),read(a[i].r);	
	sort(a+1,a+n+1,[](seg a,seg b){return a.r-a.l>b.r-b.l;});
	for(i=1;i<k;i++)ans+=a[i].r-a[i].l;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		if(a[i].l<maxn)b[++m]=a[i].r-a[i].l;
		else ta[++s]=a[i],maxn=a[i].l;
	}
	for(i=1;i<s;i++)val[i]=-ta[i].l+ta[i+1].r;
	sort(b+1,b+m+1,[](int a,int b){return a>b;});
	for(i=1;i<=m;i++)b[i]+=b[i-1];
	sort(val+1,val+s,[](int a,int b){return a>b;});
	for(i=1;i<s;i++)val[i]+=val[i-1];
	for(i=1;i<=k&&i<=s;i++)cmax(ans,val[i-1]+b[k-i]+ta[1].r-ta[s].l);
	cout<<ans<<endl;
}
signed main()
{
	freopen("lunatic.in","r",stdin);
	freopen("lunatic.out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
//	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


