#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
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
const int N=1e4+10;
int n,m,cnt;
int solved[55];
__float128 minv[N],all[N],a[N];
__float128 C(int n,int m){
	if(m>n||n<0||m<0)return 0;
	__float128 rr=1;
	for(int i=n;i>=n-m+1;i--)rr*=i;
	for(int i=1;i<=m;i++)rr/=i;
	return rr;
}
__float128 solve(int x){
	if(x==1)return a[x]=minv[n];
	if(solved[x])return a[x];
	solved[x]=1;
	__float128 now=C(n,n-x+1)*minv[n-x+1];
	for(int i=1;i<x;i++)
	now-=C(n-i,n-x)*solve(i);
	return a[x]=now;
}
void ___solve(){
	int i,j;
	read(n),read(m);
	for(i=1;i<=n;i++){
		__float128 last_ans=0,ans=0;
		for(j=m;j>=1;j--){
			ans=C(m-i*(j-1),n);	
			minv[i]+=(ans-last_ans)*j;
			all[i]+=ans-last_ans;
			last_ans=ans;
		}
		minv[i]/=all[i];
	}	
	solve(n);
	for(i=1;i<=n;i++)a[i]+=a[i-1],printf("%0.8Lf ",(long double)a[i]);	
}
signed main()
{
 	freopen("guagua.in","r",stdin);
	freopen("guagua.out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
//	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


