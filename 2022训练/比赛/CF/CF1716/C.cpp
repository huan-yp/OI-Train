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
const int N=2e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[3][N],suf[2][2][N];
int calc(int op,int cost,int step,int pos){
	int max_need=suf[op][0][pos+1]+1+pos;
	cmax(max_need,suf[op^1][1][pos]-n-n+pos);
	cmax(max_need,cost);
	return max_need+step+1;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		int ans=INF<<1;
		read(n);
		for(i=1;i<=n;i++)read(a[0][i]),
		suf[0][0][i]=a[0][i]-i,suf[0][1][i]=a[0][i]+i;
		for(i=1;i<=n;i++)read(a[1][i]),
		suf[1][0][i]=a[1][i]-i,suf[1][1][i]=a[1][i]+i;	
		
		for(j=0;j<=1;j++)
		for(i=n-1;i>=1;i--)
		cmax(suf[j][0][i],suf[j][0][i+1]),cmax(suf[j][1][i],suf[j][1][i+1]);
		
		int now=0;
		for(i=1;i<=n;i++){
			if(i&1){
				if(n!=i)cmin(ans,calc(0,now,2*(n-i),i));
				cmax(now,a[1][i]);now++;
				if(i==n)cmin(ans,now);
				cmax(now,a[1][i+1]);now++;
			}
			else{
				if(n!=i)cmin(ans,calc(1,now,2*(n-i),i));
				cmax(now,a[0][i]);now++;
				if(i==n)cmin(ans,now);
				cmax(now,a[0][i+1]);now++;
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}


