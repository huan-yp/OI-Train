#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
/*
complie options: -Wl,--stack=204800000 -std=c++14
*/
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
mt19937 mt_rand(time(NULL));
const int N=12100;
int i,j,k,m,n,s,t;
char ch[N];
int cnt[N];
bitset<N> pd[N],e;
int Rand(int l,int r){
	return (mt_rand()>>1)%(r-l+1)+l;
}
int check(int l,int r){
	return (pd[l]&pd[r]).count()>=(n+1)/2;
}
int main(){
//	freopen("consensus.in","r",stdin);
//	freopen("consensus.out","w",stdout);
	read(n);
	for(i=1;i<=n+1;i++){
		scanf("%s",ch+1);
		k=strlen(ch+1);
		int tot=0;
		for(j=1;j<=k;j++){
			int val=ch[j]-33;
			for(int j=0;j<=5&&tot+1<=2*n;j++)
			pd[i][++tot]=1<<j&val;
			if(tot>=2*n)break;
		}
	}
	if(n<=1000){
		for(i=1;i<=n+1;i++)
		for(j=1;j<i;j++){
			if(check(i,j)){
				printf("%d %d\n",i,j);
				return 0;
			}
		}
		puts("conflict");
		return 0;
	}
	while(1){
		int l=Rand(1,n+1),r=Rand(1,n+1);
		if(l==r)continue;
		if(check(l,r)){
			printf("%d %d\n",l,r);
			return 0;
		}
	}
	return 0;
}

