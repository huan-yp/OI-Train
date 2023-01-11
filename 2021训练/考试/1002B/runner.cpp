#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
int i,j,k,m,n,s,t;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(i=1;i<=100;i++)
	{
		system("data_makero.exe >o.in");
		int st=time(NULL);
		system("o.exe <o.in >o.out");
		printf("ok,finshed in %d seconds\n",time(NULL)-st);
//		system("o2.exe <o.in >o.ans");
//		system("fc o.ans o.out");	
		printf("OK,test %d\n",i);
		Sleep(1000);
	}

	return 0;
}

