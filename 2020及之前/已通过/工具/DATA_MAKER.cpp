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
char S[30]; 
int main()
{
	freopen("a.in","w",stdout);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout£©;
	srand(time(NULL));
	n=5;
	for(i=n;i>=1;i--)
	S[i]='A'+i-1;
	cout<<(S+1);
	cout<<endl;
	int l1=5;
	int l2=5;
	for(i=1;i<=l1;i++)
	cout<<char('A'+rand()%n);
	cout<<endl;
	for(i=1;i<=l2;i++)
	cout<<char('A'+rand()%n);
	cout<<endl; 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		cout<<rand()%5+1<<' ';
		cout<<endl;
	}
	return 0;
}

