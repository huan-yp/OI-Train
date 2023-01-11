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
const int N=1e6+10;
int i,j,k,n,s,t,m;
int pd[N],ans[N],sum[N];
char ch[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(m);
		memset(pd,0,sizeof(int)*(m*n+5));
		memset(ans,0,sizeof(int)*(n*m+5));
		memset(sum,0,sizeof(int)*(n*m+5));
		scanf("%s",ch+1);int first=-1,lst,now=0;
		ch[n*m+1]='1';
		for(i=1;i<=n*m+1;i++){
			if(ch[i]=='1'){
				if(pd[i%m]==0)now++,pd[i%m]=1;
				ans[i]+=now;
				if(first==-1){
					sum[i]++;
					first=i,lst=i;
					continue;
				}
				if(i-lst>m){
					sum[lst+m]--,sum[i]++;
				}
				lst=i;
			}
			else
			ans[i]+=now;
		}
		for(i=m;i<=n*m;i++)sum[i]+=sum[i-m];
		for(i=1;i<=n*m;i++)sum[i]+=sum[i-1],ans[i]+=sum[i];
		for(i=1;i<=n*m;i++)
		printf("%d ",ans[i]);
		puts("");
	}



	return 0;
}


