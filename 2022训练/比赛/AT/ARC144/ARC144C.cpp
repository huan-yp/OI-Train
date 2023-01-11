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
const int N=1e6+10;
int i,j,k,n,s,t,m,tp1,tp2;
int p[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(n),read(k);
	if(k>n/2){
		puts("-1");
		return 0;
	}
	//k,n-k
	//3k<=n<4k n=4k-5
	//k,k+1,k+2 ... 1 2 3 ... k-5 3k-4 3k-3 ... 4k-5 k-4 k-3 k-2 k-1 2k 2k+1 ... 3k-5                      
	//2k<n<3k n=3k-5
	//k k+1 k+2 ... 2k-5 2k-4 2k-3 2k-2 2k ... 3k-5 1 2 3 4 5 k
	//				k-5	 k-4
	int base=0;
	for(i=1;i+4*k-1<=n;i+=2*k){
		for(j=0;j<k;j++)p[i+j]=i+k+j;
		for(j=0;j<k;j++)p[i+j+k]=i+j;
		base+=2*k;
	}
	if(n-base>=3*k){
		for(i=1;i<=k;i++)p[base+i]=base+k+i;
		for(i=1;i<=n%k;i++)p[base+i+k]=base+i;
		for(i=1;i<=k;i++)p[base+n%k+k+i]=base+2*k+n%k+i;
		for(i=1;i<=k;i++)p[base+n%k+2*k+i]=base+n%k+i;
		for(i=0;i<n%k;i++)p[n-i]=n-i-k;
	}
	else {
		if(n%(2*k)==0){
			for(j=1;j<=k;j++)p[base+j]=base+k+j;
			for(j=1;j<=k;j++)p[base+j+k]=base+j;
		}
		else{
			for(i=1;i<=n%k;i++)p[base+i]=base+k+i;
			for(i=1;i<=k;i++)p[base+n%k+i]=base+k+n%k+i;
			for(i=1;i<=k;i++)p[base+n%k+k+i]=base+i;
		}
	}
	for(i=1;i<=n;i++)
	assert(abs(p[i]-i)>=k);
	for(i=1;i<=n;i++)cout<<p[i]<<' ';
	return 0;
}


