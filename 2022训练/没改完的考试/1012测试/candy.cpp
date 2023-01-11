#include<bits/stdc++.h>
#define pii pair<int,int>
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
const int N=160,M=12,T=2000;
int i,j,k,m,n,s,t;
int pd[N][M],ok[N][M][3],p[M]={1},tr[T],su[T],dp[2][T],mp[60000],all[2000][10],mp2[60000];
vector<pii> e[2005];
int gv(int mask,int ps){
	return int(mask/p[ps-1])%3;
}
int legal(int x,int y,int op){
	if(op==1)return x>=3&&y>=2&&pd[x][y]&&pd[x-1][y]&&pd[x-2][y]&&pd[x][y-1]&&pd[x-1][y-1]&&pd[x-2][y-1];
	return x>=2&&y>=3&&pd[x][y]&&pd[x-1][y]&&pd[x-1][y-2]&&pd[x][y-1]&&pd[x-1][y-1]&&pd[x][y-2];
}
void mve(int &mask,int ps){
	int v=gv(mask,ps);
	if(v==2)mask-=p[ps-1];
	else mask-=v*p[ps-1];
}
void sev(int &mask,int ps,int target=2){
	mask+=(target-gv(mask,ps))*p[ps-1];
}
void trans(int st,int ts){
	int rs=st;
	for(int i=1;i<=m;i++){
		if(gv(ts,i)){
			if(gv(ts,i)==2){
				if(gv(st,i)==2||gv(st,i-1)==2||gv(st,i-2)==2)return;
				sev(rs,i-2);
			}
			else{
				if(gv(st,i)||gv(st,i-1))return;
			}
			sev(rs,i);sev(rs,i-1);
		}
		else mve(rs,i);
	}
	e[i].push_back(make_pair(mp[rs],mp2[ts]));
}
void solve(){
	read(n),read(m),read(k);
	memset(ok,0,sizeof(ok));
	int ans=0;
	if(m!=s){
		memset(all,0,sizeof(all));
		su[0]=0,tr[0]=0;memset(mp,0,sizeof(mp));
		for(int mk=0,f=1;mk<p[m];mk++,f=1){
			if(gv(mk,1)||gv(mk,2)==2)f=0;
			for(i=3;i<=m;i++){
				if(gv(mk,i)&&gv(mk,i-1))break;
				if(gv(mk,i)==2&&gv(mk,i-2))break;
			}
			if(f&&i==m+1){
				tr[++tr[0]]=mk;mp2[mk]=tr[0];
				for(int i=1;i<=m;i++)if(gv(mk,i))
				all[tr[0]][++all[tr[0]][0]]=i*3+gv(mk,i);
			}
			if(gv(mk,1)&&gv(mk,2)!=gv(mk,1))continue;
			for(i=2;i<=m;i++)
			if(gv(mk,i)&&gv(mk,i+1)!=gv(mk,i)&&gv(mk,i-1)!=gv(mk,i))break;
			if(i<=m)continue;
			su[++su[0]]=mk;
			mp[mk]=su[0];
		}
		for(i=1;i<=su[0];i++)
		for(e[i].clear(),j=1;j<=tr[0];j++)
		trans(su[i],tr[j]);
	}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)pd[i][j]=1;
	for(i=1;i<=k;i++){
		int x,y;read(x),read(y);
		pd[x][y]=0;
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	for(int op=1;op<=2;op++)
	ok[i][j][op]=legal(i,j,op);
	
	memset(dp,-1,sizeof(dp));
	dp[0][mp[p[m]-1]]=0;
	for(i=0;i<n;i++){
		memset(dp[i+1&1],-1,sizeof(dp[i+1&1]));
		for(int j=1;j<=su[0];j++)if(~dp[i&1][j]&&ans-m/2<=dp[i&1][j]){
			for(auto [v,tr]:e[j]){
				for(k=1;k<=all[tr][0];k++){
					if(!ok[i+1][all[tr][k]/3][all[tr][k]%3])break;
				}
				if(k==all[tr][0]+1)cmax(dp[i+1&1][v],dp[i&1][j]+all[tr][0]);
			}
		}
		cmax(ans,*max_element(dp[i+1&1],dp[i+1&1]+su[0]+1));
	}
	cout<<ans<<endl;
	s=m;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	for(i=1;i<M;i++)p[i]=p[i-1]*3;
	read(t);
	while(t--){
		solve();
	}
	return 0;
}

