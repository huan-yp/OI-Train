#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/

int i,j,k,n,s,t,m;
int calc(int x,int y)
{
	int cntx=0,gx[40],cnty=0,gy[40],ret=0;
	memset(gx,0,sizeof(gx));
	memset(gy,0,sizeof(gy));
	
	while(x)
	{
		gx[++cntx]=x%k;
		x/=k;
	}
	while(y)
	{
		gy[++cnty]=y%k;
		y/=k;
	}
	for(int i=max(cntx,cnty);i>=1;i--)
	ret=ret*k+(gx[i]+gy[i])%k;
	
	return ret;
}
int inv(int x)
{
	int cnt=0,g[40],ret=0;
	memset(g,0,sizeof(g));
	
	while(x)
	{
		g[++cnt]=x%k;
		x/=k;
	}
	for(int i=cnt;i>=1;i--)
	ret=ret*k+(k-g[i])%k;
	
	return ret;
}
struct tagop{
	int res,val;
}tag;
set<int> st;
int calc(int x,tagop tag)
{
	if(tag.res==1)
	x=inv(x);
	x=calc(x,tag.val);
	return x;
}

signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	//x^z=y;
	//x^z^y'=0;
	//x^y'=z;
	//x'
	//x^y'=z';
	read(t);
	while(t--)
	{
		tag.res=tag.val=0;
		read(n),read(k);
		st.clear();
		for(i=0;i<n;i++)
		st.insert(i);
	
		for(i=1;i<=n;i++)
		{
			//Èô i + tag in ans Ôò i in st 
			int num=*st.begin(),ok,be=num;
			num=calc(num,tag);
			printf("%d\n",num);
			
			st.earse(be);
//			for(int v:st)
//			printf("%d ",calc(v,tag));
//			printf("\n");
			//x=x0 + tag
			//x + z= y
			//inv(( x0 + tag.res)+tag.val +y')=z
			tag.res=tag.res^1,tag.val=inv(tag.val);
			tag.val=calc(tag.val,num);
			
			cout.flush();
			read(ok);
			if(ok)break;
		}
	}
	return 0;
}

