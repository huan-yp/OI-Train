#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e3+10;
int i,j,k,n,s,t,m;
int ok[N][N];
char ch[N][N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	for(i=1;i<=n;i++)scanf("%s",ch[i]+1);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	ok[i][j]=ch[i][j]=='#';
	
	int flag=0;
	for(i=1;i<=n;i++)
	for(j=1;j+5<=n;j++){
		if(ok[i][j]+ok[i][j+1]+ok[i][j+2]+ok[i][j+3]+ok[i][j+4]+ok[i][j+5]>=4)flag=1;
	}
	for(i=1;i+5<=n;i++)
	for(j=1;j<=n;j++){
		if(ok[i][j]+ok[i+1][j]+ok[i+2][j]+ok[i+3][j]+ok[i+4][j]+ok[i+5][j]>=4)flag=1;
	}
	for(i=1;i+5<=n;i++)
	for(j=1;j+5<=n;j++){
		if(ok[i][j]+ok[i+1][j+1]+ok[i+2][j+2]+ok[i+3][j+3]+ok[i+4][j+4]+ok[i+5][j+5]>=4)flag=1;
	}
	for(i=1;i+5<=n;i++)
	for(j=6;j<=n;j++){
		if(ok[i][j]+ok[i+1][j-1]+ok[i+2][j-2]+ok[i+3][j-3]+ok[i+4][j-4]+ok[i+5][j-5]>=4)flag=1;
	}
	if(flag)puts("Yes");
	else puts("No");
	return 0;
}

