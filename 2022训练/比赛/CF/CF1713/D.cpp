#include<bits/stdc++.h>
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
const int N=18;
int i,j,k,n,s,t,m,tp1,tp2;
int a[1<<N];
int ask(int u,int v){
	printf("? %d %d\n",u,v);
	fflush(stdout);
	read(tp1);
	if(tp1==-1)
	exit(0);
	return tp1;
}
void answer(int x){
	printf("! %d\n",x);
	
	fflush(stdout);
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n);
		int ans=0;s=0;
		for(i=1;i<=1<<n;i++)a[i]=i;s=0;s=1<<n;
		while(s>=4){
			int ts=s;s=0;
			for(i=1;i+3<=ts;i+=4){
				int val=ask(a[i],a[i+2]);
				if(val==0){
					val=ask(a[i+1],a[i+3]);
					if(val==1)a[++s]=a[i+1];
					else a[++s]=a[i+3];
					continue;
				}
				if(val==2)swap(a[i],a[i+2]),swap(a[i+1],a[i+3]);
				val=ask(a[i],a[i+3]);
				if(val==0)continue;
				if(val==1)a[++s]=a[i];
				else a[++s]=a[i+3];
			}
		}
		int now=a[1];
		for(i=2;i<=s;i++){
			int val=ask(now,a[i]);
			if(val!=1)now=a[i];
		}
		answer(now);
	}
	return 0;
}


