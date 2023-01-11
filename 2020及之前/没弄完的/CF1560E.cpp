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
struct character{
	int pos,cnt;
	char ch;
	friend bool operator <(character a,character b)
	{
		if(a.cnt==0)return 0;
		if(b.cnt==0)return 1;
		return a.pos<b.pos;
	}
}a[26];
const int N=5e5+10;
int i,j,k,n,s,t,m;
char ch[N],ans[N],tmp[N];
int sum[26],need[26],lst[26];
void clear()
{
	int l1=strlen(ans+1);
	for(i=1;i<=l1;i++)
	ans[i]=0;
	
	l1=strlen(tmp+1);
	for(i=1;i<=l1;i++)
	tmp[i]=0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		memset(lst,0,sizeof(lst));
		memset(need,0,sizeof(need));
		int cnt=0,flag=0;
		clear();
		scanf("%s",ch+1);
		n=strlen(ch+1);
		for(i=1;i<=n;i++)
		{
			sum[ch[i]-'a']++;
			if(lst[ch[i]-'a']==0)cnt++;
			lst[ch[i]-'a']=i;
		}
		m=0;
		for(i=0;i<26;i++)
		{
			if(sum[i]==0)continue;
			a[m].cnt=sum[i];
			a[m].ch=i+'a';
			a[m++].pos=lst[i];
		}
		sort(a,a+cnt);
		for(i=0;i<cnt;i++)
		{
			if(a[i].cnt%(i+1)!=0)
			{
				flag=1;
				break;
			}
			need[i]=a[i].cnt/(i+1);
		}
		int now=n,len=0;
		for(i=cnt-1;i>=0;i--)
		{
			int now2=len,all=0,tl=len+need[i];
			while(1)
			{
				if(now2)
				{
					if(now>0&&ch[now]==ans[now2])
					tmp[tl--]=ch[now],now--,now2--;
					else
					{
						if(now>0&&ch[now]==a[i].ch&&all<need[i])
						tmp[tl--]=ch[now],all++,now--;
						else
						{
							flag=1;
							break;
						}
					}
				}
				else
				{
					if(now>0&&ch[now]==a[i].ch)
					all++,tmp[tl--]=ch[now],now--;
					else
					{
						flag=1;
						break;
					}
				}
				if(now2==0&&all==need[i]||now==0)break;
			}
			len=len+need[i];
			for(j=1;j<=len;j++)
			ans[j]=tmp[j];
			
			if(flag)break;
		}
		if(flag)
		{
			printf("%d\n",-1);
			continue;
		}
		printf("%s ",ans+1);
		for(i=0;i<cnt;i++)
		printf("%c",a[i].ch);
		
		
		printf("\n");
	}

	return 0;
}

