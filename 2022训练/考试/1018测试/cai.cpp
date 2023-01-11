#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1e5+10;
int i,j,k,m,n,s,t,top;
int a[N],zs[N],pd[N]; 
bitset<160> val[N],st[N];
void init(int N=700){
	for(i=2;i<=N;i++){
		if(!pd[i])zs[++s]=i;
		for(j=1;j<=s&&zs[j]*i<=N;j++)
		pd[i*zs[j]]=1;
	}
}
int main(){
	freopen("cai.in","r",stdin);
	freopen("cai.out","w",stdout);
	init();
	read(n);
	for(i=1;i<=n;i++){
		read(a[i]);
		for(j=1;j<=s;j++)
		val[i][j]=a[i]%zs[j]==0;
	}
	for(i=1;i<=n;i++){
		while(top&&(st[top]&val[i]).count()){
			val[i]|=st[top--];
		}
		st[++top]=val[i];
	}
	if(top==1)puts("Yes");
	else puts("No"); 
	return 0;
}

