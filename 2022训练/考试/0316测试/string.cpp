#include<bits/stdc++.h>
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=300005,mod=1000000021;
const LL base=179; 
int i,j,k,n,s,t,m,q,tp;
int ip[N],dep[N],top[N],sz[N],son[N],cn[N],nl[N],fa[N];
char ch[N];
struct line{
	int fr,to,len,dep;
	vector<int> pre,suf;
}link[N];
struct listline{
	int rk,ud,l,r;
	int len(){
		return r-l+1;
	}
	void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
	if(x<0)x+=mod;
	}
	int gethash(int start=0,int end=0){
		if(end==0)end=r-l+1;if(start==0)start=1;
		int res=0;
		if(ud==0)res=link[rk].pre[l+end-1]-1ll*link[rk].pre[l-2+start]*ip[end-start+1]%mod;
		else res=link[rk].suf[l+end-1]-1ll*link[rk].suf[l-2+start]*ip[end-start+1]%mod;
		Inc(res,0);return res;
	}
}ll[2][N],st[N];
vector<int> e[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*a*ret%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
void predfs(int u){
	sz[u]=1;
	for(int v:e[u]){
		if(fa[u]==v)continue;
		dep[v]=dep[u]+1;
		fa[v]=u,predfs(v);nl[u]=1;sz[u]+=sz[v]; 
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void dfs(int u){
	if(son[fa[u]]==u)top[u]=top[fa[u]];
	else top[u]=u;
	if(son[u])dfs(son[u]);
	for(int v:e[u]){
		if(v==fa[u]||v==son[u])continue;
		dfs(v);
	}
}
void jump(int x){
	auto &len=link[top[x]].len;
	auto &p=link[top[x]].pre,&s=link[top[x]].suf;
	len++;
	if(top[x]==x){
		link[x].dep=dep[x]+len-1;
		p.push_back(p[p.size()-1]*base%mod+ch[x]);
		s.push_back(s[s.size()-1]*base%mod+ch[x]);
		return ;
	}
	p.push_back(p[p.size()-1]*base%mod+ch[x]);
	jump(fa[x]);
	s.push_back(s[s.size()-1]*base%mod+ch[x]);
}
void query(int u,int v,int op){
	if(top[u]==top[v]){
		if(dep[u]>dep[v]){
			ll[op][++cn[op]]={top[u],0,link[top[u]].dep-dep[u]+1,link[top[u]].dep-dep[v]+1};
		}
		else{
			st[++tp]=(listline{top[u],1,dep[u]-dep[top[v]]+1,dep[v]-dep[top[u]]+1});
		}
		return ;
	}
	if(dep[top[u]]>dep[top[v]]){
		ll[op][++cn[op]]={top[u],0,link[top[u]].dep-dep[u]+1,link[top[u]].len};
		query(fa[top[u]],v,op);
	}
	else{
		st[++tp]=(listline{top[v],1,1,dep[v]-dep[top[v]]+1});
		query(u,fa[top[v]],op);
	}
} 
int Calc(listline a,listline b){
	int l=1,r=min(a.len(),b.len()),ret=0;
	while(r>=l){
		int mid=(l+r)/2;
		if(a.gethash(1,mid)==b.gethash(1,mid))
		ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
signed main()
{
 //	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	read(n);scanf("%s",ch+1);
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
//	int is=ch[1]!='b'||ch[2]!='a'||ch[3]!='b'||ch[4]!='a';
	predfs(dep[1]=1);
	dfs(1);read(q);
	for(i=1;i<=n;i++){
		if(nl[i])continue;
		link[top[i]].pre.push_back(0);
		link[top[i]].suf.push_back(0);
		jump(i);
	}
	ip[1]=base;
	for(i=2;i<=n;i++)ip[i]=1ll*ip[i-1]*ip[1]%mod;

	while(q--){
		int a,b,c,d;read(a),read(b),read(c),read(d);
		cn[0]=cn[1]=0;
		if(ch[a]!=ch[c]){
			printf("0\n");
			continue;
		}
		query(a,b,0);
		while(tp)ll[0][++cn[0]]=st[tp],tp--;
		query(c,d,1);
		while(tp)ll[1][++cn[1]]=st[tp],tp--;
		int now[2]={1,1},ans=0;
		while(1){
			auto &l1=ll[1][now[1]],&l0=ll[0][now[0]];
			if(l0.len()>l1.len()){
				if(l0.gethash(1,l1.len())==l1.gethash()){
					ans+=l1.len();
					l0.l+=l1.len();now[1]++;
				}
				else{
					ans+=Calc(l0,l1);
					break;
				}
			}
			else{
				if(l1.gethash(1,l0.len())==l0.gethash()){
					ans+=l0.len();l1.l+=l0.len();	
					if(l1.l>l1.r)now[1]++;now[0]++;
				}
				else{
					ans+=Calc(l0,l1);
					break;
				}
			}
			if(now[0]>cn[0]||now[1]>cn[1])break;
		}
		printf("%d\n",ans);
	}
	return 0;
}

