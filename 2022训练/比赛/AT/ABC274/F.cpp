#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
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
const int N=2005;
const double eps=1e-12;
int n,m;
int W[N],X[N],V[N];
struct mf{
	double t;
	int w;
	bool operator <(const mf &a){
		if(abs(t-a.t)>eps)return t<a.t;
	}
}q[N*2];
void ___solve(){
	int i,j,A,ans=0;
	read(n),read(A);
	for(i=1;i<=n;i++)read(W[i]),read(X[i]),read(V[i]);
	for(i=1;i<=n;i++){
		int cnt=0,maxn=0,sum=0;
		for(j=1;j<=n;j++){
			if(V[i]==V[j])
			sum+=W[j]*(X[j]>=X[i]&&X[j]<=X[i]+A);	
			else{
				if(V[i]>V[j]){
					q[++cnt]={1.0*(X[j]-X[i]-A)/(V[i]-V[j]),W[j]};
					q[++cnt]={1.0*(X[j]-X[i])/(V[i]-V[j])+eps,-W[j]};
				}
				else{
					q[++cnt]={1.0*(X[i]-X[j])/(V[j]-V[i]),W[j]};
					q[++cnt]={1.0*(X[i]+A-X[j])/(V[j]-V[i])+eps,-W[j]};
				}
			}
		}
		q[++cnt]={0,0};
		sort(q+1,q+cnt+1);maxn=sum;
		for(j=1;j<=cnt;j++){
			sum+=q[j].w;
			if(q[j].t>=0)cmax(maxn,sum);
		}
		cmax(ans,maxn);
	}	
	cout<<ans<<endl;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
//	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}

