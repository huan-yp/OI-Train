#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int i,j,k,m,n,s,t;
int a[N],st[N][20],lo[N],b[N];
int gcd(int x,int y)
{
	if(y>x)swap(x,y);
	if(y==0)return x;
	return gcd(y,x%y);
}
int ask(int l,int r)
{
	int len=lo[(r-l+1)];
	return gcd(st[l][len],st[r-(1<<len)+1][len]);
}
bool check(int x)
{
	for(i=1;i<=n;i++)
	b[i]=ask(i,i+x);
	for(i=2;i<=n;i++)
	if(b[i]!=b[1])
	return 0;
	return 1;
}
int main()
{
	cin>>t;
	for(i=1;i<N;i++)
	lo[i]=log2(i);
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];	
			a[i+n]=a[i];
			st[i+n][0]=st[i][0]=a[i];
		}
		for(j=1;j<=19;j++)
		for(i=1;i+(1<<j-1)-1<=n*2;i++)
		st[i][j]=gcd(st[i][j-1],st[i+(1<<j-1)][j-1]);
		int l=0,r=n,ans=0;
		while(r>=l)
		{
			int mid=(l+r)/2;
			if(check(mid))
			r=mid-1,ans=mid;
			else
			l=mid+1;	
		}
		cout<<ans<<endl;
	}	
	return 0;
}
