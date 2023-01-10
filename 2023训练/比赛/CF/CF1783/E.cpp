#include<bits/stdc++.h>
#define LL long long 
using namespace std;
void read(int &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=4e5+10;
int i,j,k,m,n,s,t;
int a[N],b[N],c[N],ok[N];
struct ST{
	int lo[N],st[N][20];
	void init(int *a){
		for(i=2;i<=n;i++)lo[i]=lo[i>>1]+1;
		for(i=0;i<=2*n;i++)st[i][0]=a[i];
		for(i=1;i<19;i++)
		for(j=0;j+(1<<i)-1<=2*n;j++)
		st[j][i]=max(st[j][i-1],st[j+(1<<i-1)][i-1]);
	}
	int ask(int l,int r){
		int len=lo[r-l+1];
		return max(st[l][len],st[r-(1<<len)+1][len]);
	}
}S;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n);s=0;
		memset(c,0,sizeof(int)*(2*n+3));
		for(i=1;i<=n;i++)read(a[i]);
		for(i=1;i<=n;i++)read(b[i]);
		for(i=1;i<=n;i++){
			if(a[i]<=b[i])continue;
			int x=a[i]-b[i]+1,y=b[i]-1;
			cmax(c[y],y+x);
		}
		S.init(c);
		for(i=1;i<=n;i++){
			ok[i]=1;
			for(j=0;j<=n;j+=i){
				if(j+i<S.ask(j,j+i-1))
				ok[i]=0;
			}
			s+=ok[i];
		}
		cout<<s<<'\n';
		for(i=1;i<=n;i++)if(ok[i])
		cout<<i<<' ';
		cout<<'\n';
	}
	return 0;
} 
