#include<bits/stdc++.h>
//waiting check
#define int long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=305,M=2*N*N;
int i,j,k,m,n,s,t,d;
int dp[2][M],a[N],b[M],q[M];
signed main(){
//	freopen("climb.in","r",stdin);
//	freopen("climb.out","w",stdout);
	read(n),read(d);
	for(i=1;i<=n;i++){
		read(a[i]);
		for(int j=-n;j<=n;j++)
		b[++m]=max(0ll,j*d+a[i]);
	}
	sort(b+1,b+m+1);m=unique(b+1,b+m+1)-b-1;
	memset(dp,31,sizeof(dp));
	dp[1][lower_bound(b+1,b+m+1,a[1])-b]=0;
	for(i=1;i<n;i++){
		int head=1,tail=1,now=1;
		memset(dp[(i+1)&1],31,sizeof(dp[(i+1)&1]));
		for(j=1;j<=m;j++){
			#define cost(x) abs(b[(j)]-a[i+1])+dp[i&1][(x)]
			while(head!=tail&&b[j]-b[q[head]]>d)head++;
			while(now<=m&&b[now]-b[j]<=d){				
				while(head!=tail&&cost(now)<=cost(q[tail-1]))
				tail--;
				q[tail++]=now++;
			}
			dp[(i+1)&1][j]=cost(q[head]);
			#undef cost
		}
	}
	int val=dp[n&1][lower_bound(b+1,b+m+1,a[n])-b];
	if(val<=1e18)
	cout<<val<<endl;
	else
	cout<<-1<<endl;
	return 0;
}

