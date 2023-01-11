#include<bits/stdc++.h>
using namespace std;
int n,j,k,m,i,s,t;
const int N=1e6+10;
double l,x,y;
char ch[N];
int main()
{
	scanf("%d%d%s",&m,&t,ch+1);
	int len=strlen(ch+1);
	int p=0;
	double js=1;
	for(i=1;i<=len;i++)
	{
		if(ch[i]=='.')
		{
			p=1;
			continue;
		}
		l=l*10+ch[i]-'0';
		if(p)
		js*=10;
	}
	l/=js;
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("0 0\n");
			continue;
		}
		if(n==2)
		{
			printf("%s %s\n" ,ch+1,ch+1);
			continue;
		}
		if(n==3)
		{
			printf("0 %s\n" ,ch+1,ch+1);
			continue;
		}
		if(n==4)
		{
			printf("%s 0\n" ,ch+1,ch+1);
			continue;
		}
		if(n==5)
		{
			printf("%lf %lf\n" ,l/2,l/2);
			continue;
		}
		if(n==6)
		{
			printf("0 %lf\n" ,l/2);
			continue;
		}
		if(n==7)
		{
			printf("%lf 0\n" ,l/2);
			continue;
		}
		if(n==8)
		{
			printf("%lf %lf\n" ,l/2,l);
			continue;
		}
		if(n==9)
		{
			printf("%lf %lf\n" ,l,l/2);
			continue;
		}
		i=3;
		while(i*i<n)
		i=(i-1)*2+1;
		i--;
		i/=2;
		i++;
		n-=i*i;
		i--;
		s=i;
		double now1=l/s;
		double now2=now1/2;
		x=now2,y=now2;
		for(i=2;i<=n&&i<=s*s;i++)
		{
			if(i%s==1)
			x+=now1,y=now2;
			else
			y+=now1;
		}
		i--;
		if(n>s*s)
		x=0,y=now2;
		int p=0,tt=1;
		for(j=2;i+j<=n;j++)
		{
			if((tt==s+1&&p==1)||(tt==s&&p==0))
			{
				tt=1;
				if(p==0)
				p=1;
				else
				p=0;
				if(p)
				y=0;
				else
				y=now2;
				x+=now2;
			}
			else
			{
				tt++;
				y+=now1;
			}
		}
		printf("%0.10lf %.10lf\n",x,y);
	}
	return 0;
}
