#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m;
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
const int N=53;
long long p[N],a[N];
void work()
{
	for(i=1;i<=n;i++)
	for(j=50;j>=0;j--)
	{
		if((a[i]>>j)&1)
		{
			if(p[j]==0)
			{
				p[j]=a[i];		
				break;
			}
			else
			a[i]^=p[j];
		}
	}
} 
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout£©;
	cin>>n;
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	work();
	long long ans=0;
	for(i=50;i>=0;i--)
	if(p[i]&&((ans>>i)&1)==0)
	ans^=p[i];
	cout<<ans;
	return 0;
}

