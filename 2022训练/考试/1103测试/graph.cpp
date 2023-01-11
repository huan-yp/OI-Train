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
const int N=17;
int i,j,k,m,n,s,t;
int dp[1<<N],ok[1<<N],mp[N][N],p[N],e[1<<N][2],from[1<<N];
void print(int mask,int x){
	if(mask==0)return ;
	int target=from[mask];
	mask=mask^target;
	for(i=0;i<n;i++)if(1<<i&mask)
	p[i]=x--;
	print(target,x);
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n),read(m);
	for(i=0;i<m;i++){
		int x,y;read(x),read(y);
		mp[--x][--y]=1,mp[y][x]=1;
		tie(e[i][0],e[i][1])={x,y};
	}
	memset(dp,1,sizeof(dp));
	for(int mask=0;mask<1<<n;mask++){
		ok[mask]=1;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		ok[mask]&=!(1<<i&mask&&1<<j&mask&&mp[i][j]);
	}
	dp[0]=-1;
	for(int mask=0;mask<1<<n;mask++){
		for(int mask1=mask;mask1;mask1=(mask1-1)&mask){
			int mask2=mask^mask1;
			if(!ok[mask1]||dp[mask2]+1>=dp[mask])continue;	
			dp[mask]=dp[mask2]+1;
			from[mask]=mask2;
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	print((1<<n)-1,n);
	for(i=0;i<m;i++){
		if(p[e[i][0]]>p[e[i][1]])printf("%d %d\n",e[i][0]+1,e[i][1]+1);
		else printf("%d %d\n",e[i][1]+1,e[i][0]+1);
	}
	return 0;
}

