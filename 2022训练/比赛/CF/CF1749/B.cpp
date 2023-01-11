#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
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
const int N=2e5+10;
int n,m;
int a[N],b[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	int t;read(t);
	while(t--){
		int maxn=0,ans=0;
		read(n);
		for(int i=1;i<=n;i++){
			read(a[i]),ans+=a[i];
		}	
		for(int i=1;i<=n;i++){
			read(b[i]);
			cmax(maxn,b[i]),ans+=b[i];
		}
		ans-=maxn;
		cout<<ans<<endl;
	}
	return 0;
}


