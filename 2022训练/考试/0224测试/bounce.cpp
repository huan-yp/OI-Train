#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
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
int i,j,k,n,s,t,m;
char ans[100];
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y){
	return x/gcd(x,y)*y;
}
signed main()
{
 	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	// 
	read(t);
	while(t--)
	{
		int w,h,x,y;
		read(w),read(h),read(x),read(y);	
		h*=x,w*=y;
		int g=gcd(h,w);
		m=h/g,n=w/g;
		if(m%2&&n%2)ans[0]='T',ans[1]='R';
		if(!(m%2)&&n%2)ans[0]='T',ans[1]='L';
		if(m%2&&!(n%2))ans[0]='B',ans[1]='R';
		printf("%lf\n%lld\n%s\n",sqrt(pow(m*(w/y),2)+pow(n*(h/x),2)),n+m-2,ans);
	}
	return 0;
}

