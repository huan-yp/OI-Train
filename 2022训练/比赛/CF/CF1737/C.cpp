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
const int N=1e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int a[N],b[N],cr[N],cc[N];
char ch[N];
int x1,x2,x3,y1,y2,y3,r,c;
int ok(int r1,int c1,int r2,int c2){
	return ((r1&1)==(r2&1)&&(c1&1)==(c2&1));
}
bool is(int x,int y){
	if(x!=1&&x!=n)return (x==2||x==n-1)&&(y==1||y==n);
	return y==1||y==n||y==2||y==n-1;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	t=1;
	read(t);
	while(t--){
		read(n);
		read(x1),read(y1),read(x2),read(y2),read(x3),read(y3);
		read(r),read(c);
		cr[x1]++,cr[x2]++,cr[x3]++,cc[y1]++,cc[y2]++,cc[y3]++;
		if((cr[r]>=2||cc[c]>=2)){
			puts("YES");
			cr[x1]--,cr[x2]--,cr[x3]--,cc[y1]--,cc[y2]--,cc[y3]--;
			continue;
		}
		cr[x1]--,cr[x2]--,cr[x3]--,cc[y1]--,cc[y2]--,cc[y3]--;
		if(is(x1,y1)&&is(x2,y2)&&is(x3,y3)){
			puts("NO");
			continue;
		}
		if(ok(r,c,x1,y1)||ok(r,c,x2,y2)||ok(r,c,x3,y3))puts("YES");
		else puts("NO");
	}
	return 0;
}


