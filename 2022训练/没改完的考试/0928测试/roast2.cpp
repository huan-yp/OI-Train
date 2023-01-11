#include<bits/stdc++.h>
using namespace std;
template<typename T>
int read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=3e5+10,T=30;
int i,j,k,m,n,s,t,c1,c2;
//int p1[N],p2[N],ans[N][2];
int p1[N],p2[N],ans[N],a[N];
struct Trie{
	int trie[N*(T*2)][2],to[N*(T*2)],tot=1,rk=0;
	int ok[N*(T*2)];
//	vector<int> e[N];
	void add(int u,int x,int dep){
		if(dep==-1){
			if(ok[u])return ;
			ok[u]=x;return ;
//			if(to[u]==0)to[u]=++rk;
//			e[to[u]].push_back(x);
		}
		if(1<<dep&a[x]){
			if(!trie[u][1])trie[u][1]=++tot;
			add(trie[u][1],x,dep-1);
		}
		else{
			if(!trie[u][0])trie[u][0]=++tot;
			add(trie[u][0],x,dep-1);
		}
	}
//	pair<int,int> get_ans(int u,int x,int dep=30){
//		if(dep==-1)return make_pair(e[to[u]][0],e[to[u]].back());
//		int o=bool(1<<dep&a[x]);
//		if(trie[u][o])return get_ans(trie[u][o],x,dep-1);
//		else return get_ans(trie[u][!o],x,dep-1);
//	}
	int get_ans(int u,int x,int dep){
		if(dep==-1)return ok[u];
		int o=bool(1<<dep&a[x]);
		if(trie[u][o])return get_ans(trie[u][o],x,dep-1);
		else return get_ans(trie[u][!o],x,dep-1);
	}
}T1,T2;
bool cmp(int* p1,int* p2){
	for(i=1;i<=n;i++)if(p1[i]!=p2[i])return p1[i]<p2[i];
	return 0;
}
namespace sub2{
	const int N=30;
	int a[N],p[N],ans[N];
	void solve(){
		int f=1,res=1<<30;
		memset(ans,1,sizeof(ans));
		for(i=1;i<=n;i++)read(a[i]),f*=i,p[i]=i;
		while(f--){
			int maxn=0;
			for(i=1;i<n;i++)cmax(maxn,a[p[i]]^a[p[i+1]]);
			if(maxn<res)res=maxn,memcpy(ans,p,sizeof(int)*(n+5)); 
			if(maxn==res&&cmp(p,ans))memcpy(ans,p,sizeof(int)*(n+5));
			next_permutation(p+1,p+n+1);
		}
		for(i=1;i<=n;i++)cout<<ans[i]<<' ';
	//	printf("\n%d\n",res);
	}
}
int main(){
//	freopen("roast.in","r",stdin);
//	freopen("roast.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n);int maxn=-1;
	if(n>10){
		for(i=1;i<=n;i++)read(a[i]);
		for(i=T-1;i>=0;i--){
			int cnt=0;
			for(j=1;j<=n;j++)if(1<<i&a[j])cnt++;
			if(cnt!=0&&cnt!=n){
				maxn=i;break;
			}
		}
		if(maxn==-1){for(i=1;i<=n;i++)printf("%d ",i);puts("");return 0;}
		set<int> st1,st2;int res=1<<T;
		for(i=1;i<=n;i++){
			if(1<<maxn&a[i]){
				st1.insert(i);
				T1.add(1,i,T);
			}
			else{
				st2.insert(i);
				T2.add(1,i,T);
			}
		}
		for(i=1;i<=n;i++){
			if(1<<maxn&a[i])
			ans[i]=T2.get_ans(1,i,T);
		//	tie(ans[i][0],ans[i][1])=T2.get_ans(1,i,30);
			else 
			ans[i]=T1.get_ans(1,i,T);
		//	tie(ans[i][0],ans[i][1])=T1.get_ans(1,i,30);
		//	cmin(res,a[ans[i][0]]^a[i]);
		//	cmin(res,a[ans[i][1]]^a[i]);
			cmin(res,a[ans[i]]^a[i]);
		}
		memset(p1,1,sizeof(p1)),memset(p2,1,sizeof(p2));
		for(i=n;i>=1;i--)if(1<<maxn&a[i]&&(a[ans[i]]^a[i])==res){
			for(auto v:st1)if(v!=i)p1[++c1]=v;
			p1[++c1]=i,p1[++c1]=ans[i];
			for(auto v:st2)if(v!=ans[i])p1[++c1]=v;
			break;
		}
		for(i=n;i>=1;i--)if(!(1<<maxn&a[i])&&(a[ans[i]]^a[i])==res){
			for(auto v:st2)if(v!=i)p2[++c2]=v;
			p2[++c2]=i,p2[++c2]=ans[i];
			for(auto v:st1)if(v!=ans[i])p2[++c2]=v;
			break;
		}
		int rres=0;
		if(cmp(p1,p2)){
			for(i=1;i<n;i++)cmax(rres,a[p1[i]]^a[p1[i+1]]);
			for(i=1;i<=n;i++)cout<<p1[i]<<' ';
		}
		else{
			for(i=1;i<=n;i++)cout<<p2[i]<<' ';
			for(i=1;i<n;i++)cmax(rres,a[p2[i]]^a[p2[i+1]]);
		}
		puts("");
	}
	else{
		sub2::solve();
	}
//	assert(res==rres);
//	cout<<res<<endl;
	return 0;
}

