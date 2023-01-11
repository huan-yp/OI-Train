#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=2005,P=45;
int i,j,k,n,s,t,m,tp1,tp2;
char ch[N];
int c[N][N][2][2],sum[N][N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(j=1;j<=n;j++){
			if(ch[j]=='X')continue;
			int gap=n-j+1,max_n=i-(2*m<gap);
			if(max_n==i)max_n=i+(2*m-gap)/2;
			cmin(max_n,n);
			sum[i][j]++,sum[max_n+1][j]--;
			for(k=max_n+1;k+P-i<=m&&k<=n;k+=P){
				int far=j+2*(m-(k-i));
				c[k][j][1][0]++;
				c[k][far][1][1]--;
			}
			for(;k-i<=m&&k<=n;k++){
				int far=j+2*(m-(k-i));
				c[k][j][0][0]++;
				c[k][far][0][1]--;
			}
		}		
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++){
		sum[i][j]+=-sum[i-1][j-1]+sum[i-1][j]+sum[i][j-1];
		c[i][j][0][0]+=c[i][j-1][0][0];
		c[i][j][0][1]+=c[i][j-1][0][1];
		c[i][j][1][0]+=c[i][j-1][1][0];
		c[i][j][1][1]+=c[i][j-1][1][1];
	}
	read(m);
	for(i=1;i<=m;i++){
		int x,y;
		read(x),read(y);
		int ans=0;
		ans+=c[x][y][0][0]+c[x][y][0][1];
		for(j=0;j<P&&x-j>=0;j++)
		ans+=c[x-j][y][1][0]+c[x-j][min(y+j*2,n)][1][1];
		
		ans+=sum[x][y];
		cout<<ans<<endl;
	}
	return 0;
}


