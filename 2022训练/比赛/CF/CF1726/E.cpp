#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=106+10;
int i,j,k,n,s,t,m,tp1,tp2;
int p[N],pos[N],ans[N],dp[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	//dp[n]=1:dp[n-1]
	// 		x:pos[x]=1,p[x]=1
	//		2:pos[2]=1->p[2]<=2->p[2]=1:dp[n-2]
	//		3:pos[3]=1->p[3]<=2->p[3]=1:dp[n-2]
//							   ->p[3]=2->pos[2]=3->2<=p[2]<=4,p[2]=4,pos[4]=2,1<=p[4]<=3->p[4]=1
//			x:pos[x]=1->pos[x]<=2->p[x]=1
//			->p[x]=2->pos[2]=x->x-1<=p[2]<=x+1	
//			->p[2]=x+1->pos[x+1]=2->p[x+1]=1										
//					  			  ->p[x+1]=3->pos[3]=x+1->p[3]=x+2->p[x+2]=4->
//x x+1 x+2 ... 2x-1 2 3 4 5 6 ...x-1
//
//						 	
	read(t);
	while(t--){
		read(n);
		printf("ANS:\n");
		int f=1;s=0;dp[1]=1;dp[0]=1,dp[2]=2,dp[3]=4;
		for(i=4;i<=n;i++){
			dp[i]=dp[i-1]+(i-1)*dp[i-2]+dp[i-4]*(i-3)*2;
		//	for(j=1;j<=i-3;j++)
		//	dp[i]+=dp[j]*(i-j-1);
		//	dp[i]+=(i-j)*dp[i-j-1];
		}
		memset(ans,0,sizeof(ans));
		for(i=1;i<=n;i++)p[i]=i,f*=i;
		while(f--){
			int flag=1;
			for(i=1;i<=n;i++)pos[p[i]]=i;
			for(i=1;i<=n;i++)
			if(abs(pos[i]-p[i])>1)
			flag=0;
			s+=flag;
			if(flag){
				for(i=1;i<=n;i++)printf("%d ",p[i]);
				puts("");
			}
			ans[p[1]]+=flag;
			next_permutation(p+1,p+n+1);
		}
		cout<<s<<' '<<dp[n]<<endl;
		for(i=1;i<=n;i++)cout<<ans[i]<<' ';
		puts("");
	}
	return 0;
}


