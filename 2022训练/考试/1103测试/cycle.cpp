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
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=17,M=40005;
const int modA=1e9+1e5+27,modB=1e9+1e5+29;
int i,j,k,m,n,s,t;
int ok[N],dp[(1<<N-1)+5][N*2],tpnxt[M],ins[N*2][N*2],len[N*2];
char ch[N][M],tpc[M],tcr[M];
struct Mhash{
	int A=0,B=0;
	bool operator ==(const Mhash &a){
		return a.A==A&&a.B==B;
	}
	void operator +=(int a){
		A=((A*2)+a)%modA;
//		B=((B*2)+a)%modB;
	}
	void operator +=(const Mhash &a){
		A=(A+a.A)%modA;
//		B=(B+a.B)%modB;
	}
}p[M];
void get_next(const char* a,int* next){
	int i,j=next[0]=-1,n=strlen(a+1);
	for(i=1;i<=n;i++){
		while(j!=-1&&a[i]!=a[j+1])j=next[j];
		next[i]=++j;
	}
}
int get_cycle(const char* a){
	int n=strlen(a+1);
	get_next(a,tpnxt);
	int res=n-tpnxt[n];	
	return res;
}
bool _have_substr(const char* a,const char* b){
	int i,j=0,n=strlen(b+1),m=strlen(a+1);
	get_next(b,tpnxt);
	for(i=1;i<=m;i++){
		while(j!=-1&&a[i]!=b[j+1])j=tpnxt[j];
		j++;if(j==n)break;
	}
	return i!=m+1;
}
bool have_substr(const char* a,const char* b){
	int n=strlen(b+1);
	if(_have_substr(a,b))return true;
	memcpy(tpc,b,n+5);reverse(tpc+1,tpc+n+1);
	int res=_have_substr(a,tpc);
	return res;
}
int max_insect(const char* a,const char* b){
	int maxn=0,la=strlen(a+1),lb=strlen(b+1);	
	Mhash ha,hb;
	for(int i=1;i<=min(la,lb);i++){
		if(a[la-i+1]=='1')ha+=p[i-1];
		hb+=b[i]-'0';
		if(ha==hb)maxn=i;
	}
	return maxn;
}
int main(){
//	freopen("cycle.in","r",stdin);
//	freopen("cycle.out","w",stdout);
	auto start=clock();
	p[0]+=1;
	for(i=1;i<M;i++)p[i]=p[i-1],p[i]+=0;
	read(n);
	for(i=0;i<n;ok[i]=1,i++){
		scanf("%s",ch[i]+1);
		int l=strlen(ch[i]+1);
		for(j=1;j<=l;j++)ch[i][j]=ch[i][j]=='B'?'1':'0';
	}
	for(i=0;i<n;i++)
	for(j=0;j<n;j++){
		if(strlen(ch[i]+1)!=strlen(ch[j]+1))
		ok[i]&=!(i!=j&&have_substr(ch[j],ch[i]));
		else 
		ok[i]&=!(i>j&&have_substr(ch[j],ch[i]));
	}
	int _n=n;n=0;
	for(i=0;i<_n;i++)
	if(ok[i])swap(ch[n++],ch[i]);
	for(i=0;i<n;i++)len[i]=strlen(ch[i]+1);
	for(i=0;i<n;i++)for(j=0;j<n;j++){
		ins[i<<1][j<<1]=max_insect(ch[i],ch[j]);
		reverse(ch[j]+1,ch[j]+len[j]+1);
		ins[i<<1][j<<1|1]=max_insect(ch[i],ch[j]);
		reverse(ch[i]+1,ch[i]+len[i]+1);
		ins[i<<1|1][j<<1|1]=max_insect(ch[i],ch[j]);
		reverse(ch[j]+1,ch[j]+len[j]+1);
		ins[i<<1|1][j<<1]=max_insect(ch[i],ch[j]);
		reverse(ch[i]+1,ch[i]+len[i]+1);
	}	
	int ans=N*M;
	for(int start=0;start<2;start+=2){
		int le=get_cycle(ch[start>>1]);
		for(i=1;i<M;i++)
		tcr[i]=ch[start>>1][(i-1)%le+1];
		for(i=0;i<n;i++){
			if(!have_substr(tcr,ch[i]))
			break;
		}
		if(i==n){
			cmin(ans,le);
			continue;
		}
		memset(dp,31,sizeof(dp));
		dp[1<<(start>>1)][start]=len[start>>1];
		for(int mask=1;mask<1<<n;mask++){
			for(i=0;i<2*n;i+=2){
				if(dp[mask][i]>ans)continue;
				for(j=0;j<n<<1;j+=2){
					if(1<<(j>>1)&mask)continue;
					cmin(dp[mask^(1<<(j>>1))][j|1],dp[mask][i]+len[j>>1]-ins[i][j|1]);
					cmin(dp[mask^(1<<(j>>1))][j],dp[mask][i]+len[j>>1]-ins[i][j]);
					cmin(dp[mask^(1<<(j>>1))][j|1],dp[mask][i|1]+len[j>>1]-ins[i|1][j|1]);
					cmin(dp[mask^(1<<(j>>1))][j],dp[mask][i|1]+len[j>>1]-ins[i|1][j]);
				}
			}
		}
		for(int end=0;end<n*2;end++){
			if(dp[(1<<n)-1][end]>N*M)continue;
			cmin(ans,dp[(1<<n)-1][end]-ins[end][start]);
		}
	}
	cout<<max(ans,2)<<endl;
	return 0;
}

