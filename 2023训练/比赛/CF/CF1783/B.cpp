#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=55;
int i,j,k,m,n,s,t;
int a[N][N];
void read(int &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n);
		int a1=1,a2=n*n,all=0;
		for(i=1;i<=n;i++){
			for(k=1;k<=n;k++){
				if(i%2)j=n-k+1;
				else j=k;
				if(++all%2)a[i][j]=a1++;
				else a[i][j]=a2--;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)printf("%d ",a[i][j]);
			puts("");
		}
	}
	return 0;
} 
