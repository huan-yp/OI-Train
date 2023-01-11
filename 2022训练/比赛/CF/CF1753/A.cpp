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
const int N=2e5+10;
int n,m;
int a[N];
void ___solve(){
	int i,j,s=0;
	read(n);
	for(i=1;i<=n;i++)read(a[i]),s+=a[i];
	if((s+2*n)&1){
		puts("-1");
		return ;
	}
	vector<pii> v;
	for(i=1;i<=n;i++){
		int o=i;
		while(a[i]==0&&i<=n)i++;
		if(i!=o)v.emplace_back(o,i-1);
		j=i+1;
		if(j>n)break;
		while(a[j]==0)j++;
		int len=j-i+1;
		if(len&1){
			if(a[i]!=a[j])v.emplace_back(i,j);
			else v.emplace_back(i,i),v.emplace_back(i+1,j);
		}
		else{
			if(a[i]==a[j])v.emplace_back(i,j);
			else v.emplace_back(i,i),v.emplace_back(i+1,j);
		}
		i=j;
	}
	printf("%d\n",v.size());
	for(auto [f,s]:v)printf("%d %d\n",f,s);
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


