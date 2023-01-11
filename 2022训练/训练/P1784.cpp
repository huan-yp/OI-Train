#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
#define low(x) ((x)&(-(x)))
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
const int N=10;
int i,j,k,n,s,t,m,tp1,tp2,ans=-1,cnt;
int p1[N],p2[N],p3[N],rk[N][N],lo[513],p4[N],p5[N],sum[513];
int src[N][N],a[N][N];
void dfs(int x,int y){
	if(~ans)return ;
	if(cnt==81){
		ans=1;return ;
	}
	cnt++;
	int mask=511^(p1[x]|p2[y]|p3[rk[x][y]]);
	p4[x]|=1<<y-1,p5[y]|=1<<x-1;
	for(int w=mask;w&&ans==-1;w-=low(w)){
		int v=low(w),tp1=p1[x],tp2=p2[y],tp3=p3[rk[x][y]];
		p1[x]|=v,p2[y]|=v,p3[rk[x][y]]|=v;
		int mi=0,mj=0,sm=9;a[x][y]=lo[v];
		for(int i=1;i<=9;i++)
		for(int w=511^p4[i];w;w-=low(w)){
			int p=lo[low(w)],sc=sum[511^(p1[i]|p2[p]|p3[rk[i][p]])];
			if(sc<sm)mi=i,mj=p,sm=sc;
			if(sc<sum[mask])break;
		}
		dfs(mi,mj);
		p1[x]=tp1,p2[y]=tp2,p3[rk[x][y]]=tp3;
	}
	p4[x]^=1<<y-1,p5[y]^=1<<x-1;
	cnt--;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	n=9;
	for(i=1;i<=512;i++)lo[i]=log2(i)+1,sum[i]=sum[i-low(i)]+1;
	int mi=0,mj=0;
	for(i=1;i<=9;i++)
	for(j=1;j<=9;j++){
		int x;read(x);
		rk[i][j]=(i-1)/3*3+(j-1)/3+1;
		src[i][j]=6+min(min(i-1,9-i),min(j-1,9-j));
		s+=src[i][j]*x;
		if(x==0)continue;
		p1[i]|=1<<x-1,p2[j]|=1<<x-1,p3[rk[i][j]]|=1<<x-1;
		p4[i]|=1<<j-1,p5[j]|=1<<i-1;cnt++;a[i][j]=x;
	}
	for(i=1;i<=9;i++)
	for(j=1;j<=9;j++){
		if(1<<j-1&p4[i])continue;
		if(sum[p1[i]|p2[j]|p3[rk[i][j]]]>sum[p1[mi]|p2[mj]|p3[rk[mi][mj]]]);
		mi=i,mj=j;
	}
	dfs(mi,mj);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		printf("%d ",a[i][j]);
		puts("");
	}
//	cout<<ans<<endl;
	return 0;
}

