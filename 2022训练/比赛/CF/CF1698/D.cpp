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
const int N=1e4+10;
int i,j,k,n,s,t,m;
int a[N],vis[N],exist[N];
void ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	for(int i=l;i<=r;i++)read(a[i]);
}
void solve(int l,int r,int all){
	memset(exist,0,sizeof(exist));
	if(all==1){
		for(i=l;i<=r;i++)
		if(vis[i]==0)l=i;
		printf("! %d\n",l);
		fflush(stdout);
		return ;
	}
	int cnt=0,mid=0;
	for(i=l;i<=r;i++){
		if(vis[i])continue;
		cnt++;
		if(cnt==((all/2)%2?all/2:all/2+1)){
			mid=i;
			break;
		}	
	}
	ask(l,mid);
	int a1=0,a2=0,a3=0;
	for(i=l;i<=mid;i++){
		exist[i]++;
		if(vis[a[i]])continue;
		a3++;
		if(a[i]>mid||a[i]<l){
			vis[a[i]]=1;
			a1++;
		}
		else
		exist[a[i]]--;
	}
	assert(a3==cnt);
	for(i=l;i<=mid;i++)
	if(exist[i]==1&&vis[i]==0)vis[i]=1,a2++;
	assert(a1==a2);
	if(a1%2)
	solve(mid+1,r,all-cnt-a1);
	else
	solve(l,mid,cnt-a1);
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(t);
	while(t--){
		memset(vis,0,sizeof(vis));
		read(n);
		solve(1,n,n);
	}
	return 0;
}


