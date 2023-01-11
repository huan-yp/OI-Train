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
/*



*/
int i,j,k,n,s,t,m;
int a[105];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)
		a[i]=i;
		
		if(n%2)
		{
			int tmp=a[3];
			a[3]=a[2],a[2]=a[1],a[1]=tmp;
		}	
		for(i=1+(n%2?3:0);i<=n;i+=2)
		swap(a[i],a[i+1]);
		for(i=1;i<=n;i++)
		printf("%d ",a[i]);
		cout<<endl;
		
	}
	return 0;
}

