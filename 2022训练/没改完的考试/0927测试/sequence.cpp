#include<bits/stdc++.h>
#define LIM 70000000000000ll
using namespace std;
template<typename _type>
int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=35005,M=1005;
int i,j,k,m,n,s,t;
int a[N],b[N];
long long dp[N];
int main(){
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]),a[i]-=i,b[i]=a[i];
	sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b-1;
	
	for(i=1;i<=m;i++)dp[i]=LIM+abs(a[1]-b[i]);
	for(i=1;i<=n;i++)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	dp[a[1]]=0;
	for(int i=2;i<=n;i++){
		long long minu=4e18,val=b[a[i]];
		for(int j=1;j<a[i];j++){
			minu=dp[j]<minu?dp[j]:minu;
			dp[j]=minu+LIM+val-b[j];
		}
		minu=dp[a[i]]<minu?dp[a[i]]:minu;dp[a[i]]=minu;
		for(int j=a[i]+1;j<=m;j++){
			minu=dp[j]<minu?dp[j]:minu;
			dp[j]=minu+LIM+b[j]-val;
		}
	}
	long long minu=4e18;
	for(i=1;i<=m;i++)cmin(minu,dp[i]);
	cout<<minu/LIM<<endl<<minu%LIM<<endl;
	return 0;
}

