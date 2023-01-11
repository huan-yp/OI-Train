#include<bits/stdc++.h>
#define INF 1000000000
#define double long double
#define pii pair<int,int>
#define sq(x) ((x)*(x))
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=2e5+10;
const double eps=1e-8;
int i,j,k,n,s,t,m,tp1,tp2,top;
int ok[N];
double a[N][2];
int st[N];
vector<pair<int,double>> e[N];
double calc(int p1,int p2){
	return (a[p1][1]-a[p2][1])/(a[p1][0]-a[p2][0]);
}
pair<double,double> insection(int p1,int p2,int p3,int p4){
	double k1=calc(p1,p2),b1=a[p1][1]-a[p1][0]*k1;
	double k2=calc(p3,p4),b2=a[p3][1]-a[p3][0]*k2;
	double x=(b2-b1)/(k1-k2);
	return make_pair(x,k1*x+b1);
}
namespace Solve{
	double dp[N],ans[N],sum[N];
	double ta[N][2];
	int l[N],r[N],rk[N],pre[N],suf[N],root,dst[N];
	void dfs(int u){
		for(auto [v,val]:e[u]){
			dp[v]=dp[u]+val;
			dfs(v);
		}
	}
	bool cmp(int x,int y){
		if(a[x][0]!=a[y][0])
		return a[x][0]<a[y][0];
		return x<y;
	}
	void solve(){	
		for(i=1;i<=s;i++)rk[i]=i;
		sort(rk+1,rk+s+1,cmp);memcpy(ta,a,sizeof(a));a[0][0]=-1;
		for(i=1;i<=s;i++){
			a[i][0]=ta[rk[i]][0],a[i][1]=ta[rk[i]][1];
			ok[i]=a[i][0]-a[i-1][0]>eps;
		} 
	 st[top=1]=1,st[top=2]=2;l[2]=2,r[n-1]=n-1;
		for(i=3;i<=s;i++){
			if(!ok[i])continue;
			while(top>=2&&calc(i,st[top])+eps>calc(st[top-1],st[top])){
				top--;
			}
			l[i]=st[top],st[++top]=i;
		}
		st[top=1]=s,st[top=2]=s-1;
		for(i=s-2;i>=1;i--){
			if(!ok[i])continue;
			while(top>=2&&calc(i,st[top])-eps<calc(st[top-1],st[top])){
				top--;
			}
			r[i]=st[top],st[++top]=i;
		}
		for(i=1;i<=s;i++){
			if(!ok[i])continue;
			if(a[i][1]>=a[l[i]][1]&&a[i][1]>=a[r[i]][1]){
				dst[i]=root=i;continue;
			}
			if(a[l[i]][1]>a[r[i]][1])dst[i]=l[i];
			else dst[i]=r[i];
		}
		top=0;
		for(i=2;i<=s;i++){
			if(!ok[i]){
				sum[i]=sum[i-1];
				continue;
			}
			while(top&&a[dst[i]][1]>=a[dst[st[top]]][1])top--;
			pre[i]=st[top];st[++top]=i;
			sum[i]=sum[i-1]+sqrt(sq(a[i][1]-a[i-1][1])+sq(a[i][0]-a[i-1][0]));
		}
		top=0;
		for(i=s;i>=1;i--){
			if(!ok[i])continue;
			while(top&&(a[dst[i]][1]>=a[dst[st[top]]][1]))top--;
			suf[i]=st[top];st[++top]=i;
			if(suf[i]==0)suf[i]=INF;
		}
		int d=0;
		for(i=1;i<=s;i++){
			if(!ok[i]||root==i)continue;
			if(dst[i]<i){
				d=max(pre[i],dst[i]);
				e[d].push_back(make_pair(i,sum[i]-sum[d]));
			}
			else{
				d=min(suf[i],dst[i]);
				e[d].push_back(make_pair(i,sum[d]-sum[i]));
			}
		}
		dfs(root);
		for(i=1;i<=s;i++){
			if(!ok[i])continue;
			ans[rk[i]]=dp[i];
		}
		for(i=1;i<=n;i++)printf("%0.2Lf\n",ans[i]);
	}
}

signed main()
{
 //	freopen("5.in","r",stdin);
//	freopen("5.out","w",stdout);
//	freopen(".in","w",stdout);
	scanf("%d%Lf%Lf",&n,a[1],a[1]+1);
	for(i=2;i<=n;i++)scanf("%Lf%Lf",a[i],a[i]+1);
	st[top=1]=1,st[top=2]=2;s=n;
	for(i=3;i<=n;i++){
		if(top>=2&&calc(i,st[top])>calc(st[top-1],st[top]))top--;
		while(top>=2&&calc(i,st[top])>calc(st[top-1],st[top])){
			auto [x,y]=insection(i,i-1,st[top],st[top-1]);
			a[++s][0]=x,a[s][1]=y;top--;
		}
		st[++top]=i;
	}
	st[top=1]=n,st[top=2]=n-1;
	for(i=n-2;i>=1;i--){
		if(top>=2&&calc(i,st[top])<calc(st[top-1],st[top]))top--;
		while(top>=2&&calc(i,st[top])<calc(st[top-1],st[top])){
			auto [x,y]=insection(i,i+1,st[top],st[top-1]);
			a[++s][0]=x,a[s][1]=y;top--;
		}
		st[++top]=i;
	}
	Solve::solve();
	return 0;
}
