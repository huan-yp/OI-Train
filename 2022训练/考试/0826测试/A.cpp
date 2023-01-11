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
const int N=2e5+10; 
int i,j,k,n,s,t,m,ans;
int a[N],b[N];
signed main()
{
 	freopen("river.in","r",stdin);
	freopen("river.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m);
	for(i=1;i<n;i++)read(a[i]);
	for(i=n;i<=n+m;i++)a[i]=INF;
	for(i=1;i<=m;i++)b[i]=a[i];
	for(i=m;i<n;i+=m){
		int sum=0,all=0;
		for(j=m;j>=1;j--){
			sum+=b[i+j-m];int dec=min(sum,a[i+j]);
			sum-=dec,all+=dec;
		}
		for(j=m;j>=1;j--)
		all-=b[i+j]=min(all,a[i+j]);
	}
	for(i=n;i<=n+m;i++)ans+=b[i];
	cout<<ans<<endl;
	return 0;
}


