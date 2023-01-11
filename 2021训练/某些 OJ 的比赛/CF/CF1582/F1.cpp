#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m;
const int N=1e5+10,M=515;
int a[N],minu[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(minu,1,sizeof(minu));
	read(n);	
	for(i=1;i<=n;i++)
	read(a[i]);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=511;j++)
		{
			if(a[i]>minu[j])
			cmin(minu[j^a[i]],a[i]);
		}
		cmin(minu[a[i]],a[i]);
	}
	minu[0]=0;
	for(i=0;i<=511;i++)
	if(minu[i]<512)
	s++;
	cout<<s<<endl;
	
	for(i=0;i<=511;i++)
	if(minu[i]<512)
	printf("%d ",i);
	
	return 0;
}
