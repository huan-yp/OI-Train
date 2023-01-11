#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,s,t;
inline void read(int &x)
{
	x=0;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
}
const int N=(1<<20)+10;
int head[N],nxt[N],cnt[N],sum[26],pre[N][26];
char ch[N];
struct fu{
	int v,next;
}a[N*18];
inline void work(int aa,int bb)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].v=bb;
}
inline void init()
{
	for(i=2;i<=1<<20;i++)
	for(j=1;j*i<N;j++)
	work(j*i,i);
}
void rad()
{
	char ch1=getchar();
	while(ch1<'a')
	ch1=getchar();
	while(ch1>='a')
	ch[++n]=ch1,ch1=getchar();
}
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("string.out","w",stdout);
	init();
	read(t);
	while(t--)
	{
		long long ans=0;
		nxt[0]=-1,n=0;
		rad();
		if(n<3)
		{
			printf("0\n");
			continue;
		}
		int now=-1;
		int tc=27*sizeof(int);
		memset(sum,0,sizeof(sum));
		int lst=0;
		for(i=1;i<=n;i++)
		{
			while(ch[i]!=ch[now+1]&&now!=-1)
			now=nxt[now];
			now++;
			nxt[i]=now;
			sum[ch[i]-'a']++;
			if(sum[ch[i]-'a']%2)
			lst++;
			else
			lst--;
			memcpy(pre[i],pre[i-1],tc);
			for(j=lst;j<=26;j++)
			pre[i][j]++;
		}
		memset(sum,0,sizeof(sum));
		lst=0;
		for(i=n;i>=3;i--)
		{
			sum[ch[i]-'a']++;
			int len=i-1-nxt[i-1];
			if(sum[ch[i]-'a']%2)
			lst++;
			else
			lst--;
			int tmp2=(i-1)/len;
			if((i-1)%len!=0)
			{
				ans+=pre[i-2][lst];
				continue;
			}
			for(j=head[tmp2];j;j=a[j].next)
			{
				int val=a[j].v;
				ans=ans+pre[len*val-1][lst];
			}
			ans+=pre[len-1][lst];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
