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
const int N=18,mod=998244353;
int i,j,n,s,t,m,q;
struct matri{
	int a[2][2];
	matri operator *(const matri &b){
		matri res;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		res.a[i][j]=(1ll*a[i][0]*b.a[0][j]+1ll*a[i][1]*b.a[1][j])%mod;		
		return res;
	}
}p[N],w[2];
int a[1<<N],b[1<<N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(q);
	for(i=0;i<1<<n;i++)read(a[i]);
	w[0].a[0][0]=1,w[0].a[0][1]=0;
	w[0].a[1][0]=1,w[0].a[1][1]=1;
	w[1].a[0][0]=1,w[1].a[0][1]=1;
	w[1].a[1][0]=0,w[1].a[1][1]=1;
	for(i=0;i<n;i++)
	p[i].a[0][0]=p[i].a[1][1]=1;
	for(i=1;i<=q;i++){
		int x,y;read(x),read(y);
		p[x]=p[x]*w[y^1];
	}
	for(j=0;j<n;j++){
		for(i=0;i<1<<n;i++){
			int o=bool(1<<j&i);
			b[i]=(1ll*a[i]*p[j].a[o][o]+1ll*p[j].a[o^1][o]*a[i^(1<<j)])%mod;
		}
		memcpy(a,b,sizeof(a));
	}
	for(i=0;i<1<<n;i++)printf("%d ",a[i]);
	puts("");
	return 0;
}


