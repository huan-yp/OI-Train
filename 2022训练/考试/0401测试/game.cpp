#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define pii pair<int,int>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>
void cmax(_type &x,const _type &y){x=max(x,y);}
template<typename _type>
void cmin(_type &x,const _type &y){x=min(x,y);}
const int N=3005; 
int i,j,k,m,n,s,t;
int dp[N],pd[N*10],sum[N][N];
char ch[N];
int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	n=3000;
	for(i=1;i<=n;i++){
		memset(pd,0,sizeof(pd));
		for(int d=1;d<=i;d++){
			for(int len=1;i-len*d+d>=1;len++){
				int val=sum[i-d][d]^(i-len*d<0?0:sum[i-len*d][d]);
				pd[val]=1;
			}
		}
		for(j=0;;j++)if(pd[j]==0)break;
		dp[i]=j;
		for(int d=1;d<=n;d++)sum[i][d]=(i-d>0?sum[i-d][d]:0)^dp[i];
	}
	read(t);
	while(t--){
		scanf("%s",ch+1);int val=0;
		n=strlen(ch+1);
		for(i=1;i<=n;i++){
			if(ch[i]=='1'){
				val^=dp[n-i+1];
			}
		}
		if(val)printf("1\n");
		else puts("0");
	}
	return 0;
} 
