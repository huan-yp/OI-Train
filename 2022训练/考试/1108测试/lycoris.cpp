/*
First contest after losing you.
In memory of you.
The smile lighting me up.
*/
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
const int N=10005,M=700,mod=993244353;
int i,j,k,n,t,ans;
long long dp[2][16][M*2+5];
int son[20][26],fail[20],pos[5],trs[20][6],cnt[20];
char ch[N];
void add(int u,const char* ch){
	if(*ch==0)return void(pos[++pos[0]]=u);
	add(son[u][*ch-'a']=++t,ch+1);
}
void bfs(){
	queue<int> q;
	for(i=0;i<26;i++)if(son[0][i])q.push(son[0][i]),fail[son[0][i]]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(i=0;i<26;i++){
			if(son[u][i])
			fail[son[u][i]]=son[fail[u]][i],q.push(son[u][i]);
			else
			son[u][i]=son[fail[u]][i];
		}
	}
}
int main(){
//	freopen("lycoris.in","r",stdin);
//	freopen("lycoris.out","w",stdout);
	add(0,"sakana");add(0,"chinanago");bfs();
	for(i=0;i<=t;i++)for(j=0;j<26;j++){
		if(son[i][j]==0)trs[i][0]++;
		else trs[i][++cnt[i]]=son[i][j];
	}
	read(n);scanf("%s",ch+1);
	dp[0][0][M]=1;
	for(i=0;i<n;i++){
		auto f=dp[i&1],g=dp[(i&1)^1];
		memset(g,0,sizeof(dp[(i&1)^1]));
		for(k=0;k<=t;k++){
			int end=min(M+min(i/9,(n-i)/6)+2,2*M-1);
			if(ch[i+1]=='?'){
				for(int _=1;_<=cnt[k];_++){
					int cost=trs[k][_]==pos[1]?-1:(trs[k][_]==pos[2]?1:0);
					for(j=max(M-min(i/6,(n-i)/9)-2,0);j<=end;j++)
					g[trs[k][_]][j+cost]+=f[k][j];
				}
				for(j=max(M-min(i/6,(n-i)/9)-2,0);j<=end;j++)
				g[0][j]+=1ll*trs[k][0]*f[k][j];
			}
			else{
				int cost=son[k][ch[i+1]-'a']==pos[1]?-1:(son[k][ch[i+1]-'a']==pos[2]?1:0);
				for(j=max(M-min(i/6,(n-i)/9)-2,0);j<=end;j++)	
				g[son[k][ch[i+1]-'a']][j+cost]+=f[k][j];	
			}
			for(j=max(M-min(i/6,(n-i)/9)-2,0);j<=end;j++)
			g[0][j]%=mod,g[1][j]%=mod,g[7][j]%=mod;
		}
	}
	for(i=0;i<=t;i++)ans=(ans+dp[n&1][i][M])%mod;
	cout<<ans<<endl;
	return 0;
}

