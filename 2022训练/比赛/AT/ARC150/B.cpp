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
int i,j,k,n,s,t,m,tp1,tp2;
int solve(int A,int B){
	return B%A?A-(B%A):0;
}
int solve(int A,int B,int x){
	int target=(B-1)/x+1;
	if(A>target)return INF;
	return target-A+solve(target,B);
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);	
	read(t);
	while(t--){
		int A,B;
		read(A),read(B);
		if(B<=A){
			printf("%d\n",A-B);
			continue;
		}
		int ans=B-A;
		for(i=0;i<=1e6&&A+i<=B;i++)cmin(ans,i+solve(A+i,B));
		for(i=1;i<=B/A+1&&i<=1e6;i++){
			cmin(ans,solve(A,B,i));
		}
		printf("%d\n",ans);
		
	}
	return 0;
}


