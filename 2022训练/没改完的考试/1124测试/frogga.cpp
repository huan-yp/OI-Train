#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
#define low(x) ((x)&(-(x)))
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
const int N=25;
int n,m;
int a[N],b[N];
void ___solve(){
	int i,j,k;
	int ans=0;
	read(n),read(k);
	for(i=1;i<=n;i++)read(a[i]);
	for(int mask=0;mask<1<<n;mask++){
		int cnt=0,flag=0;
		for(int x=mask;x;x-=low(x))
		b[++cnt]=a[__builtin_ctz(x)+1];
		for(int i=1;i<=cnt;i++)
		for(int j=1;j<i;j++)
		flag|=(b[i]^b[j])>k;
		
		if(!flag)cmax(ans,__builtin_popcount(mask));
		continue;
	}
	cout<<ans<<endl;
}
signed main()
{
 	freopen("frogga.in","r",stdin);
	freopen("frogga.out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


