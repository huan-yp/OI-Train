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
const int N=200005;
int i,j,k,n,s,t,m;
int cnt[27];
char ch[N];
vector<pair<int,int> > v;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int all=0,pd=-1,sum;
		memset(cnt,0,sizeof(cnt));v.clear();
		scanf("%s",ch+1);n=strlen(ch+1);
		for(i=1;i<=n;i++)
		cnt[ch[i]-'a']++;
		for(i=0;i<=25;i++)
		{
			if(cnt[i]==0)continue;
			all++;v.push_back(make_pair(cnt[i],i));
			if(cnt[i]==1&&pd==-1)
			pd=i;
		}
		sum=n-v[0].first;
		if(all==1)
		{
			printf("%s\n",ch+1);
			continue;
		}
		if(pd!=-1)
		{
			printf("%c",char('a'+pd));
			cnt[pd]--;
			for(i=0;i<=25;i++)
			{
				while(cnt[i]--)
				printf("%c",char('a'+i));
			}
			printf("\n"); 
			continue;
		}
		if(sum>=v[0].first-2)
		{
			char ch1=v[0].second+'a';
			v[0].first-=2;
			printf("%c%c",ch1,ch1);
			for(i=1;i<v.size();i++)
			{
				for(j=1;j<=v[i].first;j++)
				{
					printf("%c",(v[i].second+'a'));
					if(v[0].first)
					{
						printf("%c",char(v[0].second+'a'));
						v[0].first--;
					}
				}
			}
			printf("\n"); 
			continue;
		}	
		if(all==2)
		{
			printf("%c",char(v[0].second+'a'));
			for(i=1;i<=v[1].first;i++)
			printf("%c",char(v[1].second+'a'));
			for(i=2;i<=v[0].first;i++)
			printf("%c",char(v[0].second+'a'));
		}
		else
		{
			printf("%c",char(v[0].second+'a'));
			printf("%c",char(v[1].second+'a'));v[1].first--;
			for(i=2;i<=v[0].first;i++)
			printf("%c",char(v[0].second+'a'));
			printf("%c",char(v[2].second+'a'));v[2].first--;
			for(i=1;i<v.size();i++)
			for(j=1;j<=v[i].first;j++)
			printf("%c",char(v[i].second+'a'));
		}
		printf("\n"); 
	}
	return 0;
}

