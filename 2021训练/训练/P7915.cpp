#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template <typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
template <typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
int i,j,k,m,n,s,t,flag;
const int N=1000005;
int a[N],b[N];
char ans[N];
void print(int x,int y,int l,int r)
{
	if(x+2*n+1-y==n)
	{
		flag=1;
		return ;
	}
	if((a[x+1]==a[l-1]&&x+1<l-1)||(a[x+1]==a[r+1]&&r+1<y))
	{
		ans[++s]='L';
		if((a[x+1]==a[l-1]&&x+1<l-1))
		print(x+1,y,l-1,r);
		else
		print(x+1,y,l,r+1);
	}
	else
	{
		if((a[y-1]==a[l-1]&&x<l-1)||(a[y-1]==a[r+1]&&r+1<y-1))
		{
			ans[++s]='R';
			if((a[y-1]==a[l-1]&&x<l-1))
			print(x,y-1,l-1,r);
			else
			print(x,y-1,l,r+1);
		}
	}
}
int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("data.out","w",stdout);
	read(t);
	while(t--)
	{
		flag=0;int pos=0;
		memset(ans,0,sizeof(ans));
		read(n);s=0;
		for(i=1;i<=n*2;i++)
		read(a[i]);

		for(i=2;i<=2*n;i++)if(a[i]==a[1])pos=i;
		ans[++s]='L',print(1,2*n+1,pos,pos);
		
		if(flag==0)
		{
			s=0;ans[++s]='R';for(i=1;i<2*n;i++)if(a[i]==a[2*n])pos=i;
			print(0,2*n,pos,pos);
		}
		if(flag)
		{
			int nowl=1,nowr=2*n;
			for(i=1;i<=n;i++)
			{
				if(ans[i]=='L')
				b[i]=a[nowl++];
				else
				b[i]=a[nowr--];
			}
			for(i=n+1;i<=2*n;i++)
			{
				int val=b[n*2+1-i];
				if(a[nowl]==val)
				ans[i]='L',nowl++;
				else
				ans[i]='R',nowr--;
			}
			
			printf("%s\n",ans+1);
		}
		else
		cout<<-1<<endl;
	}
	return 0;
}
