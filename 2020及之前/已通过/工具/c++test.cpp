#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int j,k,n,s,t,m;
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
int gcd(int x,int y)
{
	return !y?x:gcd(y,x%y);	
} 
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout£©;
	while(cin>>n>>m)
	cout<<gcd(n,m)<<endl; 
	return 0;
}

