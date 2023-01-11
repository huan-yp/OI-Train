#include<bits/stdc++.h>
#include<windows.h>
#define y1 y3647
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1e7+10;
int i,j,k,n,s,t,m;
int zs[N],pd[N];
void init(){
	for(i=2;i<N;i++){
		if(!pd[i])zs[++s]=i;
		for(j=1;j<=s&&zs[j]*i<N;j++){
			pd[zs[j]*i]=1;
			if(i%zs[j]==0)break;
		}
	}
}
int Rand(int l,int r){
	return rand()*rand()%(r-l+1)+l;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	srand(time(NULL));
	init();
	int test=1000;
	for(int test=1;test<=1000;test++){
		ofstream out("power.in");
		printf("TEST %d:\n",test);
		int level=Rand(5,15);
		int p=zs[Rand(1,max(s>>level,1))];
		t=Rand(1,min((int)3e7/p, 200));
		printf("P:%d T:%d\n",p,t);
		out<<p<<' '<<t<<endl;
		for(i=1;i<=t;i++)
		out<<Rand(1,p-1)<<endl;
		
		system("power.exe");
		system("A3.exe");
		int res=system("fc power.ans power.out");
		if(res){
			puts("WA");
			return 0;
		}
		ifstream in("power.ans");
		LL first;in>>first;
		in.close();
		printf("OK,AC\n");
		printf("First ans%lld:\n",first);
	}
	



	return 0;
}


