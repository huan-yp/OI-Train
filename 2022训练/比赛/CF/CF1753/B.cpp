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
const int N=5e5+10;
int n,m;
int cnt[N];
void ___solve(){
	int i,j,x;
	read(n),read(x);
	for(i=1;i<=n;i++){
		int w;read(w);
		cnt[w]++;
	}
	int need=1,sum=0,ex=1;
	i=1;while(cnt[i]==0)i++;
	for(i;i<x;i++){
		sum+=cnt[i];
		if(sum%(i+1))break;
		sum/=i+1;
	}
	if(i==x)puts("Yes");
	else puts("No");
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
//	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


