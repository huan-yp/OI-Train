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
const int N=255;
int i,j,k,m,n,s,t,ans;
int sum[N][N];
int dp[2][N][N][N];
char ch[N][N];
int full(int top,int bottom,int left,int right){
	int size=(bottom-top+1)*(right-left+1);
	int all=sum[bottom][right]+sum[top-1][left-1]-sum[bottom][left-1]-sum[top-1][right];
	return all==0||all==size;
}
int main(){
//	freopen("painting.in","r",stdin);
//	freopen("painting.out","w",stdout);
//	int nat=1;
	read(n),read(m);
	for(i=1;i<=n;i++)scanf("%s",ch[i]+1);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
	sum[i][j]=-sum[i-1][j-1]+sum[i][j-1]+sum[i-1][j]+(ch[i][j]=='#');
	
	for(int x=1;x<=n;x++)for(int y=1;y<=m;y++){
		dp[0][x][y][y-1]=dp[1][x][y][y-1]=n;
		for(i=y;i<=m;i++){
			int &val=dp[0][x][y][i]=dp[0][x][y][i-1];
			while(val>=x&&!full(x,val,y,i))val--;
		}
	}
	for(ans=0;;ans++){
		auto f=dp[ans&1],g=dp[!(ans&1)];
		if(f[1][1][m]==n)break;
		for(int x=1;x<=n;x++)for(int y=1;y<=m;y++){	
			int p=y-1;
			for(i=y;i<=m;i++){
				int v1=f[min(f[x][y][i]+1,n)][y][i];
				while(f[x][y][p+1]>f[x][p+2][i]&&p+1<=m)p++;
				int v2=max(f[x][p+1][i],f[x][y][p+1]);
				g[x][y][i]=max(v1,v2);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

