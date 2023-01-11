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
const int N=1e6+10,mod=998244353;
int i,j,k,n,s,t,m,tp1,tp2;
struct matri{
	int n,m;
	long long a[2][2];
	matri(){memset(a,0,sizeof(a));}
	matri operator *(const matri &b){
		matri res;res.m=m,res.n=b.n;
		for(int i=0;i<res.n;i++)
		for(int j=0;j<res.m;j++)
		res.a[i][j]=(a[0][j]*b.a[i][0]+a[1][j]*b.a[i][1])%mod;
		return res;
	}
}p[32],r;
void quick(matri &base,int s){
	for(int i=0;i<30;i++)if(1<<i&s)
	base=base*p[i];
}
struct line{
	int l,r;
	void init(){
		read(l),read(r);
		if(l>r)swap(l,r);
	}
	bool operator <(const line &a){
		return l<a.l;
	}
}a[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	p[0].n=p[0].m=2;
	p[0].a[0][0]=2,p[0].a[0][1]=1;
	p[0].a[1][0]=1,p[0].a[1][1]=1;
	r=p[0];r.a[0][1]=r.a[1][1]=0;
	for(i=1;i<=30;i++)p[i]=p[i-1]*p[i-1];
	while(t--){
		read(n),read(m);	
		matri ans;ans.n=2,ans.m=1;
		ans.a[0][0]=1,ans.a[1][0]=1;
		for(i=1;i<=m;i++)
		a[i].init();
		
		sort(a+1,a+m+1);
		int lst=0;
		for(i=1;i<=m;i++){
			if(a[i].l>lst){
				quick(ans,a[i].l-lst-1);
				ans=ans*r;
			}
			cmax(lst,a[i].r);
		}
		quick(ans,n-lst);
		cout<<ans.a[1][0]<<endl;
	} 
	return 0;
}
