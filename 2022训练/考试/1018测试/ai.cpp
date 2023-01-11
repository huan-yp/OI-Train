#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define int unsigned
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
const int mod=1019260817,T=1000;
int n,m;
struct helper{
	static const int N=1e6+10,M=8e4;
	int zs[M],p114[M][3],p191[M],i114[M],i191[M],pd[N],s;
	vector<int> p[M];
	int quick(int a,int s,int ret=1){
		while(s){
			if(s&1)ret=1ull*ret*a%mod;
			a=1ull*a*a%mod;s>>=1;
		}
		return ret;
	}
	void init(){
		p114[0][1]=p191[0]=i114[0]=i191[0]=1;
		for(int i=2;i<N;i++){
			if(!pd[i]){
				zs[pd[i]=++s]=i;
				p114[s][0]=1;p114[s][1]=quick(i,114514);
				p114[s][2]=1ull*p114[s][1]*p114[s][1]%mod;
				p[s].resize(32);p[s][0]=1;p191[s]=p[s][1]=quick(i+1,1919810);
				i114[s]=quick(p114[s][1],mod-2),i191[s]=quick(p191[s],mod-2);
				for(int i=2;i<32;i++)p[s][i]=1ull*p[s][i-1]*p[s][1]%mod;
			}
			for(int j=1;j<=s&&zs[j]*i<N;j++){
				pd[zs[j]*i]=1;
				if(i%zs[j]==0)break;
			}
		}
	}
	vector<int> get_primes(int x){
		vector<int> v;
		for(int i=1;zs[i]<=sqrt(x+0.5);i++)while(x%zs[i]==0)
		v.push_back(i),x/=zs[i];
		if(x!=1)v.push_back(pd[x]);
		return v;
	}
	int get_big_prime(int x){
		auto v=get_primes(x);
		if(x==1||zs[v.back()]<=T)return 0;
		return v.back();
	}
	int ask_pow(int rk,int val){
		val-=2;
		while(p[rk].size()<val+1)
		p[rk].push_back(1ull*p[rk].back()*p[rk][1]%mod);
		return 1ull*p[rk][val]*p114[rk][2]%mod;
	}
}H;
namespace solve_l{
	const int T=320,N=102400;
	int array[N];
	struct solver{
		int b[T];
		short a[N];
		void init(){
			for(int i=0;i<=n/T;i++){
				b[i]=(i?b[i-1]:0);
				for(int j=i*T+1;j<i*T+T;j++)
				a[j]+=a[j-1];
				b[i]+=a[i*T+T-1];
			}
		}
		void update(int pos,int delta){
			for(int i=pos/T;i<=n/T;i++)b[i]+=delta;
			for(int i=pos;i<pos/T*T+T;i++)a[i]+=delta;
		}
		int query(int x){
			if(x<T)return a[x];
			return b[x/T-1]+a[x];
		}
		int query(int l,int r){
			return query(r)-query(l-1);
		}
	}a[180];
	vector<int> get_primes(int x){
		auto v=H.get_primes(x);
		if(!v.empty()&&H.zs[v.back()]>::T)v.pop_back();
		return v;
	}
	void init(int* ay){
		memcpy(array,ay,sizeof(array));
		for(int i=1;i<=n;i++){
			auto v=get_primes(array[i]);
			for(auto w:v)a[w].a[i]++;
		}
		for(int i=1;i<170;i++)a[i].init();
	}
	void update(int pos,int val){
		int cnt=0,lst=0;
		for(auto w:get_primes(array[pos])){
			if(lst&&lst!=w)a[lst].update(pos,-cnt),cnt=0;
			lst=w,cnt++;
		}
		a[lst].update(pos,-cnt);lst=cnt=0;
		for(auto w:get_primes(val)){
			if(lst&&lst!=w)a[lst].update(pos,cnt),cnt=0;
			lst=w,cnt++;
		}
		a[lst].update(pos,cnt);array[pos]=val;
	}
	int query(int l,int r){
		int prod=1;
		for(int i=0;i<170;i++){
			int c=a[i].query(l,r);
			switch (c){
				case 0:
					break;	
				case 1:
					prod=1ull*prod*H.p114[i][1]%mod;
					break;
				default :
					prod=1ull*prod*H.ask_pow(i,c)%mod;
			}
		}	
		return prod;
	}
}
namespace solve_r{
	const int N=1e5+10,M=45;
	int tot,tot_itv;
	int p[N],mp[M][M],cnt[H.M],start[M];
	struct solver{
		int cnt[H.M];
		int L,R,l,r,ans;
		void init(int x,int y,int as){
			memcpy(cnt,solve_r::cnt,sizeof(cnt));
			L=l=x,R=r=y;ans=as;
		}
		inline void add(int x,int &ret){
			cnt[x]++;
			if(cnt[x]>2)return void(ret=1ull*ret*H.p191[x]%mod);
			ret=1ull*ret*H.p114[x][1]%mod;
		}
		void rmv(int o){
			cnt[o]--;
			if(cnt[o]>=2)ans=1ull*ans*H.i191[o]%mod;
			else ans=1ull*ans*H.i114[o]%mod;
		}
		int get_ans(int x,int y){
			int ret=ans;
			while(l>x)add(p[--l],ret);
			while(r<y)add(p[++r],ret);
			while(l<L)cnt[p[l++]]--;
			while(r>R)cnt[p[r--]]--;
			return ret;
		}
		
	}a[M*(M+1)/2];
	void init(int* array){
		int len=n/(M-1)+1;
		for(int i=1;i<=n;i++)p[i]=H.get_big_prime(array[i]);
		for(int i=len;i<n;i+=len)start[++tot]=i;
		for(int i=1;i<=tot;i++){
			memset(cnt,0,sizeof(cnt));
			int now=1,k=start[i];
			for(int j=i+1;j<=tot;j++){
				for(;k<=start[j];k++){
					cnt[p[k]]++;
					if(cnt[p[k]]<=2)now=1ull*now*H.p114[p[k]][1]%mod;
					else now=1ull*now*H.p191[p[k]]%mod;
				}
				mp[i][j]=++tot_itv;
				a[tot_itv].init(start[i],start[j],now);
			}
		}
	}
	void update(int pos,int val){
		int c=H.get_big_prime(val);
		if(p[pos]){
			for(int i=1;i<=tot_itv;i++){
				if(pos<=a[i].r&&pos>=a[i].l)
				a[i].rmv(p[pos]);
			}	
		}
		if(c){
			for(int i=1;i<=tot_itv;i++){
				if(pos<=a[i].r&&pos>=a[i].l)
				a[i].add(c,a[i].ans);
			}	
		}
		p[pos]=c;
	}
	int query(int l,int r){
		int lp=lower_bound(start+1,start+tot+1,l)-start;
		int rp=upper_bound(start+1,start+tot+1,r)-start-1;
		int rk=mp[lp][rp];
		if(rk)return a[rk].get_ans(l,r);
		else{
			a[0].L=a[0].l=l;a[0].ans=1;
			a[0].R=a[0].r=l-1;
			return a[0].get_ans(l,r);
		}
	}
}
void update(int pos,int val){
	solve_l::update(pos,val);solve_r::update(pos,val);
}
int query(int l,int r){
	return 1ull*solve_l::query(l,r)*solve_r::query(l,r)%mod;
}
signed main()
{
	int ans=0,t,i;
	int* a=new int[(int)(1e5+10)];
	H.init();
	read(n),read(m),read(t);
	for(i=1;i<=n;i++)read(a[i]);
	solve_l::init(a);
	solve_r::init(a);
	for(i=1;i<=m;i++){
		int op,x,y;
		read(op),read(x),read(y);
		x^=t*ans,y^=t*ans;
		if(op==1)update(x,y);
		else printf("%u\n",ans=query(x,y));
	}
	return 0;
}

