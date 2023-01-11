#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=1e3+10; 
int i,j,k,n,s,t,m,tp1,tp2,tot;
int pd[N],d[N],col[N];
int ask(int u){
	printf("? %d\n",u);
	fflush(stdout);
	return read(u);
}
void print(){
	printf("! ");
	for(i=1;i<=n;i++)printf("%d ",col[i]);
	fflush(stdout);
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);d[0]=-1;
	while(t--){
		read(n);tot=0;
		memset(pd,0,sizeof(pd));
		memset(col,0,sizeof(col));
		for(i=1;i<=n;i++)read(d[i]);
		while(1){
			int u=0,c=-1;
			for(i=1;i<=n;i++)if(d[i]>d[u]&&!pd[i])u=i;
			if(u==0)break;
			vector<int> e;
			e.push_back(u);
			while(d[u]--){
				int v=ask(u);
				e.push_back(v);
				if(pd[v]){
					c=col[v];
					break;
				}
			}
			if(c==-1)c=++tot;
			for(auto v:e)col[v]=c,pd[v]=1;
		}
		print();
	}
	return 0;
}


