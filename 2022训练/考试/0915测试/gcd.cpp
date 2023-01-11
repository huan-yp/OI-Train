#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=1005,M=N*N; 
int i,j,k,n,s,t,m,res,top;
int a[N][N],lst[N][N],ans[N][N],f[M],st[N];
struct point{
	int x,y;
	bool operator <(const point &a){
		if(y!=a.y)return y<a.y;
		return x<a.x;
	}
}p[M],pos[M];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m);
	for(i=0;i<=m;i++)lst[0][i]=i;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
		read(a[i][j]);
		pos[a[i][j]]={i,j};
		f[1]+=i*j;
		lst[i][j]=j;
	}
	for(int w=2;w<=n*m;w++){
		s=0;
		for(j=w;j<=n*m;j+=w)
		p[++s]=pos[j];
		sort(p+1,p+s+1);
		for(i=1;i<=s;i++){
			int x,y;x=p[i].x,y=p[i].y;
			lst[x][y]=lst[x][y-1];
			if(lst[x-1][y]==y)st[top=1]=x-1,st[top=2]=x,ans[x][y]=y-lst[x][y];
			else{
				while(lst[st[top]][y]<=lst[x][y])top--;
				ans[x][y]+=ans[st[top]][y]+(y-lst[x][y])*(x-st[top]);	
				st[++top]=x;
			}
			f[w]+=ans[x][y];
		}
		for(i=1;i<=s;i++){
			auto [x,y]=p[i];
			ans[x][y]=0,lst[x][y]=y;
		}
	}
	for(i=n*m;i>=1;i--){
		for(j=2*i;j<=m*n;j+=i)
		f[i]-=f[j];
		res+=f[i]*i;
	}
	cout<<res<<endl;
	return 0;
}


