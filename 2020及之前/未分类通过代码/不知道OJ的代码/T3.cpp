#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
#define int long long
using namespace std;
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
int a,b,c,d,e,f,g,h,i,j,k,m,ans;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
	ans=a+b+c+d+e+f+g+h*5+50;
	if(ans>=i)
	printf("AKIOI");
	else
	printf("AFO");
	return 0;
}

