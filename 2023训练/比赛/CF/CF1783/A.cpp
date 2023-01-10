#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=55;
int i,j,k,m,n,s,t;
int a[N];
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
		for(i=1;i<=n;i++)read(a[i]);
		sort(a+1,a+n+1); 
		sort(a+2,a+n+1,[](int a,int b){return a>b;});
		if(a[1]==a[2])puts("NO");
		else{
			puts("YES");
			for(i=1;i<=n;i++)printf("%d ",a[i]);
			puts("");
		}
	}
	return 0;
} 
