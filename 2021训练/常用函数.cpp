inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
void freo(int x)
{
	string o=".out";string d="data";char ch[21];
	memset(ch,0,sizeof(ch));int g[21],cnt=0,p=1;
	while(x||p){cnt++;g[cnt]=x%10;x/=10;p=0;}
	for(int i=1;i<=cnt/2;i++)swap(g[i],g[cnt-i+1]);
	for(int i=1;i<=cnt;i++)d+=g[i]+48;d+=o;
	for(int i=0;i<d.length();i++)ch[i]=d[i];freopen(ch,"w",stdout);
}//freo(ii) 向dataii.out中输出 
void frei(int x)
{
	string o=".in";string d="data";char ch[21];
	memset(ch,0,sizeof(ch));int g[21],cnt=0,p=1;
	while(x||p){cnt++;g[cnt]=x%10;x/=10;p=0;}
	for(int i=1;i<=cnt/2;i++)swap(g[i],g[cnt-i+1]);
	for(int i=1;i<=cnt;i++)d+=g[i]+48;d+=o;
	for(int i=0;i<d.length();i++)ch[i]=d[i];freopen(ch,"r",stdin);
}//frei(ii) 从dataii.in中读入 
void frem(int x)
{
	string o=".in";string d="data";char ch[21];
	memset(ch,0,sizeof(ch));int g[21],cnt=0,p=1;
	while(x||p){cnt++;g[cnt]=x%10;x/=10;p=0;}
	for(int i=1;i<=cnt/2;i++)swap(g[i],g[cnt-i+1]);
	for(int i=1;i<=cnt;i++)d+=g[i]+48;d+=o;
	for(int i=0;i<d.length();i++)ch[i]=d[i];freopen(ch,"w",stdout);
}//frem(ii) 向dataii.in中输出。 
LL Rand(LL l,LL r)
{
	if(l>r)
	swap(l,r);
	return ((1ll*rand()<<16)|(rand()))%(r-l+1)+l;
}//生成一个[l,r]的随机数 
LL RandND(LL l,LL r)
{
	int sum=0;
	for(int i=1;i<=T;i++)
	sum+=Rand(l,r);
	
	return sum/10;
}
double RandDB(double l,double r)
{
	return Rand(1,10000)/10000.0*(r-l)+l;
}
