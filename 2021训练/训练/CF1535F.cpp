#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int mod[]={19260817,1000200031,1000200029};
const int N=4e5+10;
int i,j,k,n,s,t,m;
int cnt[N][26],p[N][2],base[N][2]={{1,1}},pd[N];
LL ans;
string ch[N];
pair<int,int> h1[N],h2[N];
map<pair<int,int>,int> mp;
inline int get(const int &a,const int &b){return (a-1)*(m+1)+b;}
pair<int,int> has(int rk,int x,int y)
{
	int fi=(1ll*p[m][1]*(h2[get(rk,y)].first-h2[get(rk,x-1)].first)%mod[1]+mod[1])%mod[1],
	se=(1ll*p[m][2]*(h2[get(rk,y)].second-h2[get(rk,x-1)].second)%mod[2]+mod[2])%mod[2];
	return make_pair((0ll+h1[get(rk,x-1)].first-h1[get(rk,y)].first+h1[get(rk,m)].first+fi+mod[1])%mod[1],
	(0ll+h1[get(rk,x-1)].second-h1[get(rk,y)].second+h1[get(rk,m)].second+se+mod[2])%mod[2]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin.sync_with_stdio(false);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		ch[i]=" ";string tmp;
		cin>>tmp;ch[i]+=tmp;
	}
	m=ch[1].length()-1;p[0][1]=p[0][2]=base[0][1]=base[0][2]=1;
	for(i=1;i<=m;i++)
	p[i][1]=p[i-1][1]*128ll%mod[1],p[i][2]=p[i-1][2]*128ll%mod[2];
	for(i=1;i<26;i++)
	base[i][1]=base[i-1][1]*1009ll%mod[1],base[i][2]=base[i-1][2]*1009ll%mod[2];

	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		s=get(i,j);
		h1[s]=make_pair((h1[s-1].first+1ll*ch[i][j]*p[j-1][1])%mod[1],
		(h1[s-1].second+1ll*ch[i][j]*p[j-1][2])%mod[2]);
		h2[s]=make_pair((1ll*base[ch[i][j]-'a'][1]*p[m][1]+h2[s-1].first)%mod[1],
		(1ll*base[ch[i][j]-'a'][2]*p[m][2]+h2[s-1].second)%mod[2]);

		for(k=0;k<26;k++)
		cnt[s][k]=cnt[s-1][k];
		cnt[s][ch[i][j]-'a']++;
	}
	if(n<=2000)
	{
		for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			int l=0,r=n+1,flag1=1,flag0=1,flag=1;
			for(k=1;k<=m;k++)
			if(ch[i][k]!=ch[j][k])break;l=k-1;
			for(k=m;k>=1;k--)
			if(ch[i][k]!=ch[j][k])break;r=k+1;
			
			if(l>=r)continue;
			for(k=0;k<26;k++)if(cnt[get(i,m)][k]!=cnt[get(j,m)][k])flag=0;
			if(flag==0){ans+=1337;continue;}
			
			for(int lst='a',k=l+1;k<r;k++)
			{
				if(ch[i][k]<lst){flag0=0;break;}
				lst=ch[i][k];
			}
			for(int lst='a',k=l+1;k<r;k++)
			{
				if(ch[j][k]<lst){flag1=0;break;}
				lst=ch[j][k];
			}
			if(flag0||flag1)ans+=1;
			else ans+=2;
		}
	}
	else
	{
		int cnt1=0,cnt2=0,cnt1337=0,cnt0=0;
		for(int l=1;l<=m;l++)
		{
			for(i=1;i<=n;i++)pd[i]=1;
			for(int r=l+1;r<=m;r++)
			{
				mp.clear();
				for(i=1;i<=n;i++)
				{
					pd[i]&=(ch[i][r]>=ch[i][r-1]);				
					if(pd[i]==1&&(r==n||ch[i][r]>ch[i][r+1])&&(l==1||ch[i][l-1]>ch[i][l]))
					mp[has(i,l,r)]++;
				}
				for(i=1;i<=n;i++)
				{
					if(pd[i])continue;
					auto h=has(i,l,r);
					if(mp.find(h)!=mp.end())
					cnt1+=mp[h];
				}
			}
		}
		mp.clear();
		for(i=1;i<=n;i++)
		{
			auto h=has(i,1,m);
			cnt2+=mp[h];
			mp[h]++;
		}
		cnt1337=n*(n-1)/2-cnt2;
		mp.clear();
		for(i=1;i<=n;i++)
		{
			auto h=has(i,1,0);
			cnt0+=mp[h];
			mp[h]++;
		}
		cnt2-=cnt1+cnt0;
		ans=cnt1+cnt2*2+cnt1337*1337;
	}
	cout<<ans<<endl;
	return 0;
}

