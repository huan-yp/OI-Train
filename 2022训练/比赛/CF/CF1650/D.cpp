#include<bits/stdc++.h>
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
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=2e3+10;
int i,j,k,n,s,t,m;
int a[N],ans[N];
void shift(int a[],int pre,int val){
	int b[N];
	for(j=1;j<=pre;j++){
		b[(j+val-1)%pre+1]=a[j];
	}
	for(j=1;j<=pre;j++)a[j]=b[j];
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--){
		read(n);
		for(i=1;i<=n;i++)read(a[i]);
		for(i=n;i>=1;i--){
			int pos=0;
			for(j=1;j<=i;j++)if(a[j]==i)pos=j;
			ans[i]=pos%i;
			shift(a,i,i-pos);
		}
		for(i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}

	return 0;
}

