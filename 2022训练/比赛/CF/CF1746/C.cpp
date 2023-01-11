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
const int N=1e5+10;
int i,j,n,s,t,m;
int a[N],ans[N];
void solve(){
	read(n);
	for(i=1;i<=n;i++){
		read(a[i]);
		ans[a[i]]=min(i+1,n);
	}
	for(i=1;i<=n;i++)cout<<ans[i]<<' ';
	puts("");
}
signed main()
{
	read(t);
	while(t--){
		solve();	
	}
	return 0;
}


