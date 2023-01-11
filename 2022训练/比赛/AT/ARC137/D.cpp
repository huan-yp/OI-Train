#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int T=20;
const int N=1<<T;
int i,j,k,n,s,t,m;
int a[N],f[T+5][N];
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=n;i++){
		f[T][((1<<T)-1)^(n-i)]=a[i];
	}
	for(i=T-1;i>=0;i--){
		for(int mask=0;mask<1<<T;mask++){
			if(1<<i&mask)
			f[i][mask]=f[i+1][mask];
			else
			f[i][mask]=f[i+1][mask]^f[i+1][mask|1<<i];
		}
	}
	for(i=1;i<=m;i++)printf("%d ",f[0][i-1]);
	
	
	
	return 0;
}


