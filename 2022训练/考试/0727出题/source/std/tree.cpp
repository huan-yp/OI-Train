#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=202005;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],p[N],b[N],lst[N],far[N];
struct Double{
	double val;
	int p;
	Double cap(Double x){
		while(abs(x.val)>1e18){
			x.val/=2;
			x.p++;
		}
		while(abs(x.val)<1e-18){
			x.val*=2;
			x.p--;
		}
		return x;
	}
	void operator =(int x){p=0,val=x;}
	Double operator +(const Double &x){
		if(x.p-p>50)return x;
		if(p-x.p>50)return *this;
		return cap({val+x.val*pow(2,x.p-p),p});
	}
	void operator +=(const Double &x){*this=*this+x;cap(x);}
	Double operator -(){return Double{-val,p};}
	Double operator -(Double &x){return cap((*this)+(-x));}
	Double operator /(const Double &x){return cap({val/x.val,p-x.p});}
	double get(){return val*pow(2.0,p);}
};
Double dp[N][2],sum[N][2];
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout); 
	read(n);lst[1]=1;
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=n;i++)read(b[i]),p[b[i]]=i;
	for(i=1;i<=n;i++)a[i]=p[a[i]];
	for(i=1;i<=n;i++)p[a[i]]=i;
	for(i=2;i<=n;i++){
		if(p[i]>p[i-1])lst[i]=lst[i-1];
		else lst[i]=i;
	}
	dp[1][0]=1,dp[1][1]=1;
	sum[1][0]=1,sum[1][1]=1;
	far[1]=1;
	for(i=2;i<=n;i++){
		for(j=far[i-1]+1;j<=i;j++){
			if(a[p[j-1]+1]<=i||p[j-1]==n)continue;
			else break;
					
			if(k!=n)break;
		}	
		far[i]=--j;
		if(far[i]>=lst[i]){
			dp[i][0]=sum[j-1][0]-sum[lst[i]-2][0];
			dp[i][1]=(sum[j-1][1]-sum[lst[i]-2][1])+(sum[j-1][0]-sum[lst[i]-2][0]);
		}
		sum[i][0]=dp[i][0]+sum[i-1][0];
		sum[i][1]=dp[i][1]+sum[i-1][1];
	}
	printf("%0.3lf",(dp[n][1]/dp[n][0]).get());
	return 0;
}
