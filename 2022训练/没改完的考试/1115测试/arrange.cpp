#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=15;
int i,j,k,m,n,s,t;
int p[N],l[N],r[N],a[N],q[N];
vector<pair<int,int>> e,w;
void solve(){
	read(n);e.clear(),w.clear();
	for(i=1;i<=n;i++)read(l[i]),read(r[i]);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(l[i]>r[j])e.emplace_back(j,i);
	for(i=1;i<=n;i++)for(j=1;j<i;j++)if(l[i]<=r[j]&&l[j]<=r[i])w.emplace_back(i,j);
	int f=1;
	for(i=1;i<=n;i++)f*=i,p[i]=i;
	int res=n;
	while(f--){
		int flag=0,fin=0;
		next_permutation(p+1,p+n+1);
		for(auto [s,t]:e){
			if(p[s]>p[t]){
				flag=1;
				break;
			}
		}
		if(flag)continue;
		for(auto [s,t]:w){
			cmax(fin,abs(p[s]-p[t]));
			if(fin>res)break;
		}
		if(fin<res){
			res=fin;
			memcpy(a,p,sizeof(p));
		}
	}
	cout<<res<<endl;
	for(i=1;i<=n;i++)q[a[i]]=i;
	for(i=1;i<=n;i++)cout<<l[q[i]]<<' '<<r[q[i]]<<endl;
}
int main(){
	freopen("arrange.in","r",stdin);
	freopen("arrange.out","w",stdout);
	int tot;read(tot);
	while(tot--){
		solve();
	}
	return 0;
}

