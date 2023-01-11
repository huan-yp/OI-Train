#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
template<typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
const int N=1e5+10;
int i,j,k,m,n,s,t;
int dir[N];
char chx[N],chy[N];
string x[N],y[N];
bool cmpxy(const string &a,const string &b)
{
	if(a.length()!=b.length())
	return a.length()<b.length();
	return a<b; 
}
bool cmpdy(const string &a,const string &b)
{
	if(a.length()!=b.length())
	return a.length()>b.length();
	return a>b; 
}

//cmp(a,b):a<b ·µ»Ø True 
int main()
{
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	read(n);
	for(i=1;i<=n;i++)
	{
		scanf("%s%s",chx+1,chy+1);
		int lenx=strlen(chx+1),leny=strlen(chy+1);
		for(j=1;j<=lenx;j++)
		x[i]+=chx[j];
		for(j=1;j<=leny;j++)
		y[i]+=chy[j];
	}
	x[n+1]=x[1],y[n+1]=y[1];
	
	//010
	//203
	//040
	for(i=1;i<=n;i++)
	{
		if(x[i]==x[i+1])
		{
			if(cmpdy(y[i+1],y[i]))
			dir[i]=1;
			else
			dir[i]=4;
		}
		else
		{
			if(cmpdy(x[i+1],x[i]))
			dir[i]=3;
			else
			dir[i]=2;
		}	
		
	}
	dir[n+1]=dir[1];
	for(i=1;i<=n;i++)
	{
		if(dir[i]==1&&dir[i+1]==2)s++;
		if(dir[i]==2&&dir[i+1]==4)s++;
		if(dir[i]==3&&dir[i+1]==1)s++;
		if(dir[i]==4&&dir[i+1]==3)s++;
	}
	cout<<s<<endl;
	return 0;
}

