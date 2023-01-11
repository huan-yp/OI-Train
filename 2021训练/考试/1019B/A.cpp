#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template <typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
template <typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
const int N=5050;
int i,j,k,m,n,s,t,p;
int a[N],b[N],cnt[N],val[N],pos[N];
int ans[N][2];
void reserve(int l,int r)
{
	if(l==r)return ;
	ans[++s][0]=l-1,ans[s][1]=r;
	for(int i=1;i<=(r-l+1)/2;i++)
	swap(val[l+i-1],val[r-i+1]);
}
void solve(int l,int r)
{
	for(i=l;i<=r;i++)
	{
		for(j=i;;j++)
		{
			if(val[j]==i)
			{
				reserve(i,j);
				break;
			}
		}
	}
}
int main()
{
//	freopen("devil.in","r",stdin);
//	freopen("devil.out","w",stdout);
	read(n),read(p);p++;
	for(i=1;i<=n;i++)
	read(a[i]),b[i]=a[i];
	
	sort(b+1,b+n+1),m=unique(b,b+n+1)-b-1;
	for(i=1;i<=n;i++)
	a[i]=lower_bound(b,b+m+1,a[i])-b;
	
	for(i=1;i<=n;i++)
	cnt[a[i]]++;
	for(i=1;i<=n;i++)
	cnt[i]=cnt[i-1]+cnt[i];
	
	for(i=1;i<=n;i++)
	val[i]=cnt[a[i]]--,pos[val[i]]=i;
	
	if(a[p]!=a[pos[p]])
	{
		printf("-1\n");
		return 0;
	}
	swap(val[p],val[pos[p]]);
	int cnt1=0,cnt2=0;
	for(i=p-1;i>=0;i--)
	{
		int flag=0;
		for(j=i;j>=1;j--)
		{
			if(val[j]>p&&(flag==0||val[j]<val[flag]))
			flag=j;
		}
		if(flag)
		{
			reserve(flag,i);
			cnt1++;
		}
	}
	for(i=p+1;i<=n;i++)
	{
		int flag=0;
		for(j=i;j<=n;j++)
		{
			if(val[j]<p&&(flag==0||val[j]>val[flag]))
			flag=j;
		}
		if(flag)
		{
			reserve(i,flag);
			cnt2++;
		}
	}
	if(cnt1!=cnt2)
	{
		printf("-1\n");
		return 0;
	}
	reserve(p-cnt1,p+cnt2);
	solve(1,p-1);
	solve(p+1,n);
	cout<<s<<endl;
	for(i=1;i<=s;i++)
	printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}

