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
const int mod1=1e9+7,mod2=1e9+9,base1=173,base2=191;
int i,j,k,n,s,t,m,now,flag,hash1,hash2;
int a[105];
vector<int> v[8];
set<pair<int,int> > st;
void h(int x)
{
	hash1=1ll*base1*hash1+x%mod1;
	hash2=1ll*base2*hash2+x%mod2;
}
int cancontinue()
{
	if(v[0].size()==52)return 1;
	if(v[0].size()==0)return 2;
	
	hash1=0,hash2=0;
	for(int val:v[0])	
	h(val);
	
	for(i=1;i<=7;i++)
	{
		h(11);
		for(int val:v[i])
		h(val);
	}
	if(st.count(make_pair(hash1,hash2)))return 3;
	
	st.insert(make_pair(hash1,hash2));
	return 0;
}
int ok()
{
	int siz=v[now].size();
	if(siz<3)return 0;	
	if((v[now][0]+v[now][1]+v[now][siz-1])%10==0) 
	{
		v[0].push_back(v[now][0]);
		v[0].push_back(v[now][1]);
		v[0].push_back(v[now][siz-1]);
		v[now].pop_back();
		v[now].earse(v[now].begin());
		v[now].earse(v[now].begin());
		return 1;
	}
	if((v[now][0]+v[now][siz-2]+v[now][siz-1])%10==0) 
	{
		v[0].push_back(v[now][0]);
		v[0].push_back(v[now][siz-2]);
		v[0].push_back(v[now][siz-1]);
		v[now].pop_back();
		v[now].pop_back();
		v[now].earse(v[now].begin());	
		return 1;
	}
	if((v[now][siz-3]+v[now][siz-2]+v[now][siz-1])%10==0) 
	{
		v[0].push_back(v[now][siz-3]);
		v[0].push_back(v[now][siz-2]);
		v[0].push_back(v[now][siz-1]);
		v[now].pop_back();
		v[now].pop_back();
		v[now].pop_back();
		return 1;
	}
	return 0;
}
signed main()
{
	//freopen("data.in","w",stdout);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	while(1)
	{
		t=0;
		cin>>a[1];
		if(a[1]==0)
		break;
		flag=0,now=1;
		st.clear();
		for(i=0;i<=7;i++)v[i].clear();
		for(i=2;i<=52;i++)cin>>a[i];
		for(i=1;i<=7;i++)v[i].push_back(a[i]);
		for(i=8;i<=52;i++)v[0].push_back(a[i]);
		
		while(++t)
		{
			v[now].push_back(*v[0].begin());
			v[0].earse(v[0].begin());
			
			while(1)
			if(ok()==0)
			break;
			
			flag=cancontinue();
			if(flag)
			break;
			
			now++;
			if(now>7)now-=7;
			while(v[now].size()==0)
			now++,now=(now-1)%7+1;
		}
		if(flag==1)
		printf("Win : %d\n",t+7);
		if(flag==2)
		printf("Loss: %d\n",t+7);
		if(flag==3)
		printf("Draw: %d\n",t+7);
	}
	return 0;
}

