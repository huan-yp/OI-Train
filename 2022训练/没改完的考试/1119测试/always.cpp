#include<bits/stdc++.h>
//waiting check
using namespace std;
template<typename T1>
void read(T1 &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=1e5+10;
int i,j,k,m,n,s,t;
int a[2][N],sum[2][N];
char ch[2][N],ans[N];
int count(int op,int l,int r,int t){
	return t?sum[op][r]-sum[op][l-1]:r-l+1-count(op,l,r,1);
}
bool solve(){
	int l0,r0,l1,r1,len0,len1;
	read(l0),read(r0),read(l1),read(r1);
	len0=r0-l0+1,len1=r1-l1+1;
	if(count(1,l1,r1,1)==len1)return count(0,l0,r0,1)==len0&&len0>=len1&&(len0-len1)%3==0;
	int co1=min(a[1][r1],len1),co0=min(a[0][r0],len0);
	if(co1>co0)return 0;
	int z=co1;r1-=z,r0-=z,len0-=z,len1-=z;
	int c0=count(0,l0,r0,0),c1=count(1,l1,r1,0),w=min(len0,a[0][r0]);
	if(w%3)c0+=2;
	if(c0==0&&c1!=0&&w==0)return 0;
	if((c0&1)!=(c1&1)||c0>c1)return 0;
	return 1;
}
int main(){
	#ifndef DEBUG
	freopen("always.in","r",stdin);
	freopen("always.out","w",stdout);
	#endif
	scanf("%s%s",ch[0]+1,ch[1]+1);
	n=strlen(ch[0]+1),m=strlen(ch[1]+1);
	for(i=1;i<=n;i++)if(ch[0][i]=='A')a[0][i]=a[0][i-1]+1;
	for(i=1;i<=m;i++)if(ch[1][i]=='A')a[1][i]=a[1][i-1]+1;
	for(i=1;i<=n;i++)sum[0][i]=sum[0][i-1]+(ch[0][i]=='A');
	for(i=1;i<=m;i++)sum[1][i]=sum[1][i-1]+(ch[1][i]=='A');
	int q;read(q);
	for(int i=1;i<=q;i++)
	ans[i]='0'+solve();
	cout<<ans+1<<endl;
	return 0;
}
