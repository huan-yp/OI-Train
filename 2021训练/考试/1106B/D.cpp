#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=5e5+10;
int i,j,k,m,n,s,t,op;
char lst;
char ch[N],ans[N];
char to(char ch)
{
	if(ch=='a')return 'a';
	if(ch=='a'+k-1)return 'a';
	return ch-1;
}
int main()
{
	read(t);
	while(t--)
	{
		read(n),read(k);
		for(i=1;i<=n+4;i++)
		ans[i]=0;
		
		scanf("%s",ch+1);
		lst=ch[1],op=1;
		for(i=1;i<=n-1;i++)
		{
			if(lst=='a')
			{
				ans[i]=lst;
				lst=ch[i+1],op=1;
				continue;
			}
			if(op==1)
			{
				if(to(lst)>ch[i+2]&&to(ch[i+1])>ch[i+2]&&i<=n-2)
				{
					ans[i]=ch[i+2];ans[i+1]=to(lst);
					lst=ch[i+1],op=0;
					i++;continue;
				}
				if(to(lst)<=to(ch[i+1]))
				{
					ans[i]=to(lst);
					op=1;lst=ch[i+1];
				}
				else
				{
					ans[i]=to(ch[i+1]);
					op=0;
					if(ch[i+1]=='a')lst=to(lst);
				}
			}
			else
			{
				if(i<=n-2&&lst>ch[i+2]&&ch[i+1]>ch[i+2])
				{
					ans[i]=ch[i+2],ans[i+1]=lst;
					lst=ch[i+1],op=0;
					i++;continue;
				}
				if(lst<=ch[i+1])
				{
					ans[i]=lst;
					lst=ch[i+1],op=1;
				}
				else
				{
					ans[i]=ch[i+1];
					op=0;
				}
			}
		}
		if(op)
		ans[n]=to(lst);
		else
		ans[n]=lst;
		printf("%s\n",ans+1);
	}
	return 0;
}

