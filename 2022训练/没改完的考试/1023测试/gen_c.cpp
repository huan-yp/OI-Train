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
int i,j,k,m,n,s,t;
mt19937 mt_rand(time(NULL));
int Rand(int l,int r){
	if(l>r)swap(l,r);
	return mt_rand()%(r-l+1)+l;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int test=0;test<=1;test++){
		ofstream o("1.in");
		n=Rand(70,100),m=Rand(2,100);
		o<<n<<' '<<m/2*n<<endl;
		for(int i=1;i<=n;i++)o<<Rand(1,m)<<' ';
		o<<endl;
		for(int i=1;i<=n;i++)o<<Rand(1,m)<<' ';
		o<<endl;
		system("count <1.in >1.out");
//		system("c <1.in >1.ans");
//		int ret=system("fc 1.out 1.ans");
//		if(ret){
//			printf("WA");
//			exit(0);
//		}
//		ifstream in("1.ans");
//		int answer;in>>answer;
//		printf("OK,test %d,ans is %d\n",test,answer);
	
	}
	return 0;
}

