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
const int N=2005;
int i,j,k,m,n,s,t,ans;
int p[N];
char ch[N];
int main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	read(n),read(m);
	int lstcnt=0;
	for(i=1;i<=n;i++){
		scanf("%s",ch+1);
		int now=0,cnt=lstcnt,dec=0;
		for(j=m;j>=1;j--){
			int val=ch[j]-'0';
			while(p[j]&&dec)p[j]--,dec--;
			lstcnt-=p[j],now^=p[j]&1;
			if(now^val){
				p[j]++;now^=1;
				if(lstcnt)lstcnt--,dec++;
				else cnt++,ans++;
			}
		}
		lstcnt=cnt;
	}
	cout<<ans<<endl;
	return 0;
}

