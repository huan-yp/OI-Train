#include<bits/stdc++.h>
#define LL long long
#define U unsigned
#define INF 0x7fffffffffffffff
#define MINF -0x8000000000000000
#define rep(i,a,b) for(LL i=(a);i<=(b);i++)
#define per(i,a,b) for(LL i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pii pair<LL,LL>
#define vii vector<vector<LL> >
#define vi vector<LL>
using namespace std;
bool isp(LL x){
	if(x<2)return 0;
	for(LL i=2;i<=sqrt(x);i++){
		if(x%i==0) return 0;
	}
	return 1;
}
inline LL read()
{
	LL x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
LL gcd(LL x,LL y){
	return !y?x:gcd(y,x%y);
}
LL FPW(LL x,LL y,LL mod){
	LL res=1;
	for(;y;y>>=1){
		if(y%2)res=res*x%mod;
		x=x*x%mod;
	}
	return res;
}
/*LL N,M,S,T,l,r=0x7f7f7f7f,m,h[600000],n[600000],w[600000],dt[600000],en,dis[600000];
struct node{
	LL id,dis;
	bool operator < (const node &B) const{return dis>B.dis;}
};
void dij(){
	priority_queue<node>q;
	bool vis[600000]={};
	memset(dis,0x7f7f7f7f,sizeof dis);
	dis[S]=0;
	q.push((node){S,0});
	while(q.size()){
		LL x=q.top().id;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(LL j=h[x];j;j=n[j]){
			LL y=dt[j],ww=w[j];
			if(dis[y]<=dis[x]+ww)continue;
			dis[y]=dis[x]+ww;
			q.push((node){y,dis[y]});
		}
	}
    return ;
}
void add(LL x,LL y,LL z=0){
	dt[++en]=y,n[en]=h[x],w[en]=z,h[x]=en;
	return ;
}*/
/**/
LL phi[19198100],prime[19198100],pc;
void ETB_PRM_init(LL MAXN){
	phi[1]=1;
	for(LL i=2;i<MAXN;i++){
		if(phi[i]==0){
			prime[pc++]=i;
			phi[i]=i-1;
		}
		for(LL j=0;j<pc&&i*prime[j]<MAXN;j++){
			if(i%prime[j]==0){
				phi[i*prime[j]]=prime[j]*phi[i];
				break;
			}else{
				phi[i*prime[j]]=(prime[j]-1)*phi[i];
			}
		}
	}
}
LL jc[600000];
LL mod=1e9+7;
LL C(LL n,LL m){
    if(m>n)return 0;
    return ((jc[n]*FPW(jc[m],mod-2,mod))%mod*FPW(jc[n-m],mod-2,mod)%mod);
}


namespace segtree{
	LL a[200000],tag[600000][2],tree[600000],cnt;
	void push_up(LL now){
		tree[now]=tree[now*2]+tree[now*2+1];
		return ;
	}
	void build(LL now,LL l,LL r){
		tag[now][0]=1;
	    tag[now][1]=0;
		if(l==r){
			tree[now]=a[l];
		}else{
			LL mid=(l+r)/2;
			build(now*2,l,mid);
			build(now*2+1,mid+1,r);
			push_up(now);
		}
		return ;
	}
	void push_down(LL now,LL l,LL r){
		LL mid=(l+r)/2;
		tree[now*2]=(tree[now*2]*tag[now][0]+(mid-l+1)*tag[now][1]);
		tree[now*2+1]=(tree[now*2+1]*tag[now][0]+(r-mid)*tag[now][1]);
		tag[now*2][0]=(tag[now*2][0]*tag[now][0]);
	    tag[now*2+1][0]=(tag[now*2+1][0]*tag[now][0]);
	    tag[now*2][1]=(tag[now*2][1]*tag[now][0]+tag[now][1]);
	    tag[now*2+1][1]=(tag[now*2+1][1]*tag[now][0]+tag[now][1]);
		tag[now][0]=1;
		tag[now][1]=0;
		return ;
	}
	void update(LL now,LL l,LL r,LL x,LL y,LL t){
		if(y<l||r<x){
			return ;
		}
		if(x<=l&&y>=r){
			tree[now]=(tree[now]*t);
			tag[now][0]=(tag[now][0]*t);
			tag[now][1]=(tag[now][1]*t);
		}else{
			push_down(now,l,r);
			LL mid=(l+r)/2;
			update(now*2,l,mid,x,y,t);
			update(now*2+1,mid+1,r,x,y,t);
			push_up(now);
		}
		return ;
	}
	void update2(LL now,LL l,LL r,LL x,LL y,LL t){
		if(y<l||r<x){
			return ;
		}
		if(x<=l&&y>=r){
			tree[now]=(tree[now]+(r-l+1)*t);
			tag[now][1]=(tag[now][1]+t);
		}else{
			push_down(now,l,r);
			LL mid=(l+r)/2;
			update2(now*2,l,mid,x,y,t);
			update2(now*2+1,mid+1,r,x,y,t);
			push_up(now);
		}
		return ;
	}
	LL query(LL now,LL stdl,LL stdr,LL l,LL r){
		if(r<stdl||stdr<l){
			return 0;
		}
		if(l<=stdl&&stdr<=r){
			return tree[now];
		}
		push_down(now,stdl,stdr);
		LL m=(stdl+stdr)/2;
		return(query(now*2,stdl,m,l,r)+query(now*2+1,m+1,stdr,l,r));
	}
}
LL N,M,K;
string s;
map<LL,bool>isexi;
map<LL,LL>num;
vector<LL>Mfs; 
map<LL,LL>Mfj;
vector<LL>ans;
void solve(){
	N=read(),M=read();
	if(N==1){
		cout<<N<<endl;
		rep(i,1,N){
			printf("%lld ",i);
		}
	}
	ETB_PRM_init(1000000);
	if(isp(M)){
		Mfj[M]=1;isexi[M]=1;
		Mfs.pb(M);
	}else{
		LL j=0;
		while(M>1){
			LL tot=0;
			while(M%prime[j]==0){
				M/=prime[j];
				tot++;
			}
			if(tot){
				Mfj[prime[j]]=tot;isexi[prime[j]]=1;
				Mfs.pb(prime[j]);
			}
			j++;
		}
	}
	N--;
	rep(i,1,N){
		LL adn=N-i+1,mnn=i;
		for(LL x:Mfs){
			while(adn%x==0){
				adn/=x;
				num[x]++;
			}
		}
		for(LL x:Mfs){
			while(mnn%x==0){
				mnn/=x;
				num[x]--;
			}
		}
		bool flg=0;
		for(LL x:Mfs){
			if(num[x]<Mfj[x]){
				flg=1;break;
			}
		}
		if(!flg){
			ans.pb(i+1);
		}
	}
	N++;
	cout<<ans.size()<<endl;
	for(LL x:ans){
		printf("%lld ",x);
	}
/*	jc[0]=1;
	rep(i,1,514514)jc[i]=jc[i-1]*i%mod;
	rep(i,0,N-1){
		cout<<C(N-1,i)<<" ";
	} */
	
}
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	LL T=1;
	while(T--){
		solve();
	}
    return 0;
}
//ÖÒ£¡³Ï£¡
//ÍÅ£¡½á£¡
//±Ø£¡Ê¤£¡


