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
const int mod=998244353,N=2e5+10;
int n,m;
int a[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1;a=1ll*a*a%mod;
	}
	return ret;
}
void ___solve(){
	int i,j;
	int cnt[2]={},ic[2]={};
	read(n);
	for(i=1;i<=n;i++){
		read(a[i]),cnt[a[i]]++;
	}
	for(i=1;i<=n;i++){
		if(i<=cnt[0])
		ic[1]+=a[i];
		else
		ic[0]+=!a[i];
	}
	int ans=0;
	assert(ic[0]==ic[1]);
	while(ic[0]){
		int total=1ll*n*(n-1)/2%mod;
		int now=1ll*ic[0]*ic[1]%mod;
		ans+=1ll*total*quick(now,mod-2);
		ans%=mod;
		ic[0]--;
		ic[1]--;
	}
	cout<<ans<<endl;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


