#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
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
const int N=2e5+10;
int n,m,tail,head;
pii q[N*10];
int* dp[N], *from[N];
bool* pd[N];
char* ch[N], *ans[N];
bool legal(int x,int y){
	return ch[x][y-1]!='#'&&ch[x+1][y]!='#'&&ch[x-1][y]!='#'&&ch[x][y+1]!='#';
}
void print(int x,int y){
	ans[x][y]='#';
	if(y==1)return ;
	print((from[x][y]-1)/m,(from[x][y]-1)%m+1);
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	int t;read(t);
	while(t--){
		int i,j;
		tail=head=N*5;
		read(n),read(m);
		int cnt=0;
		for(int i=0;i<=n+1;i++){
			ch[i]=new char[m+5];
			memset(ch[i],0,sizeof(char)*(m+5));
			dp[i]=new int[m+5];
			pd[i]=new bool[m+5];
			from[i]=new int [m+5];
			memset(pd[i],0,sizeof(bool)*(m+5));
			memset(dp,1,sizeof(int)*(m+5));
			ans[i]=new char[m+5];
			cnt+=4*m;
		}
		for(int i=1;i<=n;i++){
			scanf("%s",ch[i]+1);
			memcpy(ans[i],ch[i],sizeof(char)*(m+5));
		}		
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)pd[i][j]=legal(i,j);
		
		for(i=1;i<=n;i++){
			if(!pd[i][1])continue;
			if(ch[i][1]=='#')q[--head]=make_pair(i,1),dp[i][1]=0;
			else q[tail++]=make_pair(i,1),dp[i][1]=1;
		}
		while(tail!=head){
			auto [x,y]=q[head++];
			vector<pii> v{{-1,-1},{-1,1},{1,-1},{1,1}};
			for(auto [dx,dy]:v){
				int tx=x+dx,ty=y+dy;
				if(!pd[tx][ty]||dp[tx][ty]<=dp[x][y]+(ch[tx][ty]!='#'))continue;
				from[tx][ty]=x*m+y;
				if(ch[tx][ty]=='#')dp[tx][ty]=dp[x][y],q[--head]=make_pair(tx,ty);
				else dp[tx][ty]=dp[x][y]+1,q[tail++]=make_pair(tx,ty);
			}
		}
		int min_pos=0;
		for(i=1;i<=n;i++)if(dp[i][m]<dp[min_pos][m])min_pos=i;
		if(min_pos){
			puts("YES");
			print(min_pos,m);
			for(i=1;i<=n;i++)printf("%s\n",ans[i]+1);
		}
		else{
			puts("NO");
		}
		for(int i=0;i<=n+1;i++){
			delete [] ans[i];
			delete [] dp[i];
			delete [] ch[i];
			delete [] pd[i];
			delete [] from[i];
		}
	}
	return 0;
}

