#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=2e5+10;
int i,j,k,m,n,s,t;
char ch[N];
int calc(int x){
	for(i=1;i<=45000;i++)if(i*(i-1)/2==x)return i;
	throw "No illegal number";
}
int main(){
//	freopen("str.in","r",stdin);
//	freopen("str.out","w",stdout);
	//freopen(".in","w",stdout);
//	read(n),cout<<n<<endl;
	read(t);
	while(t--){
		int a,b,c,d;
		read(a),read(b),read(c),read(d);
		int c0,c1;
		try{
			c0=calc(a);
			c1=calc(d);
			if(a==0||d==0){
			    if(b+c==0){
			        for(i=1;i<=c0&&a;i++)printf("0");
			        for(i=1;i<=c1&&d;i++)printf("1");
			        if(a==0&&d==0)printf("0");
			        puts("");
			        continue;   
			    }
			}
			if(b+c!=c0*c1)throw "illegal b+c";
			int p1=c/c0,pos1=c0-c%c0+1;
			for(i=1;i<=p1;i++)printf("1");
			for(i=1;i<=c0;i++){
				if(pos1==i)printf("1");
				printf("0");
			}
			for(i=p1+bool(c%c0);i<c1;i++)printf("1");
			puts("");
		}
		catch (const char* e){
			puts("impossible");
		}
	}
	return 0;
}

