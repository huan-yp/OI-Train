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
const int N=4e5+10;
int i,j,k,n,s,t,m,q;
int st[25][N],lo[N];
int ask(int l,int r){
	if(l>r)swap(l,r);
	int len=lo[r-l+1];
	return min(st[len][l],st[len][r-(1<<len)+1]);
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(m),read(n);
	
	for(i=2;i<=n;i++)lo[i]=lo[i>>1]+1;
	for(i=1;i<=n;i++)
	read(st[0][i]),st[0][i]=m-st[0][i];
	
	for(i=1;i<=20;i++)
	for(j=1;j+(1<<i)-1<=n;j++)
	st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	read(q);
	for(i=1;i<=q;i++){
		int x1,x2,y1,y2;
		read(y1),read(x1),read(y2),read(x2),read(k);
		if(k==0){
			if(x1==x2&&y1==y2)puts("YES");
			else puts("NO");
			continue;
		}
		y1=m-y1+1,y2=m-y2+1;
		if(abs(x1-x2)%k||abs(y1-y2)%k||ask(x1,x2)<(y1%k==0?k:y1%k))puts("NO");
		else puts("YES");
	}
	return 0;
}


