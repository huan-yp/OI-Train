#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,s,t;
long long a,b,c,d,e,f;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
		long long t1=a*c*e;
		long long t2=b*d*f;
		if(t1==t2&&t1==0)
		{
			if(d==0)
			{
				printf("FON\n");
				continue;
			}
			if(c==0)
			{
				printf("MEI\n");
				continue;
			}
			if(b==0)
			{
				printf("FON\n");
				continue; 
			}
			if(a==0)
			{
				printf("MEI\n");
				continue;
			}
			if(f==0)
			{
				printf("FON\n");
				continue;
			}
			if(e==0)
			{
				printf("MEI\n");
				continue;
			}
			
		} 
		if(t2>t1)
		printf("MEI\n");
		else
		printf("FON\n");
	}
	return 0;		
}
