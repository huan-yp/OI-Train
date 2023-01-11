#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename _type>
void read(_type &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<class _type1,class _type2>void cmax(_type1 &a,const _type2 &b){if(b>a)a=b;}
template<class _type1,class _type2>void cmin(_type1 &a,const _type2 &b){if(b<a)a=b;}
const int N=243333,mod=998244353,M=1919811;
int i,j,k,m,n,s,t,maxb,maxlen,inv=1;
int val[N],len[N],b[N],p[M],belong[N]; 
char ch[M];
pair<string,int> str[N];
map<pair<string,int>,int> rkt;
vector<pair<string,int>> e2[N]; 
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;	
	}
	return ret;
}
int Rand(int l,int r){
	return 1ll*rand()*rand()%(r-l+1)+l;
}
bool cmp(const pair<string,int> &a,const pair<string,int> &b){
	return a.first+b.first<b.first+a.first;
}
int getval(pair<string,int> tmp,int val=0){
	auto tp=tmp.first;
	for(int i=0;i<tp.length();i++)
	val=(10ll*val+tp[i]-'0')%mod;
	return val;
}
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
struct SegmentTree{
	int a[N<<2];
	void push_up(int rt){
		a[rt]=1ll*a[rt<<1|1]*a[rt<<1]%mod;	
	}
	void build(int l,int r,int rt){
		if(l==r){
			a[rt]=b[l];return ;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void updata(int l,int r,int rt,int x,int c){
		if(l==r){
			a[rt]+=c,a[rt]%=mod;return ;
		}
		int mid=(l+r)/2;
		if(x<=mid)updata(l,mid,rt<<1,x,c);
		else updata(mid+1,r,rt<<1|1,x,c);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y){
		if(x>y)return 1;
		if(x<=l&&y>=r)return a[rt];
		int mid=(l+r)/2,ret=1;
		if(x<=mid)ret=quert(l,mid,rt<<1,x,y);
		if(y>mid)ret=1ll*ret*quert(mid+1,r,rt<<1|1,x,y)%mod;
		return ret;
	}
}T;
signed main(){
//	freopen("joining.in","r",stdin);
//	freopen("joining.out","w",stdout);
//	freopen(".in","w",stdout);
	srand(114514);
	read(n);p[0]=1;
	for(i=1;i<M;i++)p[i]=10ll*p[i-1]%mod;
	for(i=1;i<=n;i++){
		read(b[i]);inv=1ll*inv*b[i]%mod;
		for(j=1;j<=b[i];j++){
			scanf("%s",ch+1);string tmp="";
			int le=strlen(ch+1);
			for(k=1;k<=le;k++)tmp+=ch[k];
			e2[i].push_back(make_pair(tmp,++t)),str[++s]=make_pair(tmp,t);
			maxlen+=tmp.length();
		}
	}
	for(i=1;i<=s;i++)
	swap(str[i],str[Rand(1,i)]);
	
	sort(str+1,str+s+1,cmp);
	for(i=1;i<=s;i++)
	rkt[str[i]]=i,len[i]=str[i].first.length(),val[i]=getval(str[i]);
	
	for(i=1;i<=n;i++){
		for(auto tmp:e2[i])
		belong[rkt[tmp]]=i;
	}	
	int ans=0;T.build(1,n,1);
	for(i=1;i<=s;i++){
		ans+=1ll*val[i]*T.quert(1,n,1,1,belong[i]-1)%mod*T.quert(1,n,1,belong[i]+1,n)%mod;
		ans%=mod;
		T.updata(1,n,1,belong[i],p[len[i]]-1);
	}
	cout<<1ll*ans*quick(inv,mod-2)%mod<<endl;
	return 0;
}

