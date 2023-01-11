#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){b=max(a,b);}
const int N=2e5+10;
int i,j,k,m,n,s,t;
int a[N];
signed main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	read(n),read(k);
	for(i=1;i<=k-1;i++)
	a[i]=1;
	if(k)
	{
		int l=i,r=n,mid=(l+r)/2;
		a[mid+(k%2==0)]=1;
		int n0=n/2,n1=n-n0;n0+=1;
		int ans=n0*(n0-1)/2+n1*(n1-1)/2;
		cout<<n*(n+1)/2-ans<<endl;
	}
	else
	printf("%lld\n",0);
	for(i=1;i<=n;i++)
	cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}

