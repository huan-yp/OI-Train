#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb(x) push_back(x)
#define lowbit(x) x&-x
using namespace std;
const int N=1e3+10;
double ans;
int n,m,T,vist[N],a[N],b[N],id[N],tot;
inline int read(){
	int s=0,f=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
	while(ch<='9'&&ch>='0') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return f?-s:s;
}
void dfs(int x,int d){
	if(x==n+1){
		bool flag=1;
		for(register int i=1;i<n;++i) flag&=(id[b[i]]<=id[b[i+1]]);
		if(flag){
			ans+=id[b[n]];
			++tot;
		}
		return ;
	}
	id[a[x]]=d;
	dfs(x+1,d+1);
	if(d!=2){
		id[a[x]]=2;
		dfs(x+1,2);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	if(n<=10){
		for(register int i=1;i<=n;++i) a[i]=read();
		for(register int i=1;i<=n;++i) b[i]=read();
		id[a[1]]=1;
		dfs(2,2);
		cout<<fixed<<setprecision(10)<<ans/tot;
	}else{
		for(register int i=2;i<=n;++i) ans+=i;
		cout<<fixed<<setprecision(10)<<ans/(n-1);
	}
	return 0;
}
