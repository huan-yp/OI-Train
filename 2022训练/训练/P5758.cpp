#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
#define isn(x) (x!=im&&x!=ia&&x!=ie&&x!=-1)
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1005;
int i,j,k,n,s,t,m,tp1,tp2,im,ia,i0,ie,lst,ok,sol,fg,arr,fr,maxn;
int len[N],num[N][15],cnt[15],pd[15],ass[15][15],cnt_a[15],use[15];
int mid[N],rk[16];
char as[]="0123456789=+*";
set<string> st;
int get(int a[],int l,int r){
	int sum=0,prod=1,now=0;
	for(int i=l;i<=r;i++){
		if(pd[a[i]]<=9){
			now=now*10+pd[a[i]];
		}
		else{
			prod*=now;now=0;
			if(pd[a[i]]==11){
				sum+=prod,prod=1;
			}
		}
		
	}
	if(abs(sum)>=1e4)return 0;
	return sum+prod*now;
}
int eq(int a[],int l,int lim){
	
}
void dfs(int dep){
//	if(fg)return ;
	if(fg||sol>10)return ;
	if(dep==fr+1){
		int i=1;s++;
		int n1=get(num[i],1,mid[i]-1),n2=get(num[i],mid[i]+1,len[i]);
		if((n1*10<n2||n2*10<n1)&&s>=2e6)fg=1;
		if(n1!=n2)return ;
	}
	if(dep==10){
		for(int i=1;i<=n;i++){
			s++;
			int n1=get(num[i],1,mid[i]-1),n2=get(num[i],mid[i]+1,len[i]);
			if((n1*10<n2||n2*10<n1)&&s>=2e6)fg=1;
			if(n1!=n2)return ;
		}
		ok=1;sol++;
		for(int i=0;i<=12;i++){
			if(pd[i]==-1){
				for(int j=1;j<=9;j++)
				if(!use[j])ass[i][j]=1;
			}
			else{
				ass[i][pd[i]]=1;
			}
		}
		return ;
	}
	if(cnt[rk[dep]]==0||~pd[rk[dep]]){
		dfs(dep+1);
		return ;
	}
	for(int i=1;i<=9;i++){
		if(use[i])continue;
		use[i]=1;pd[rk[dep]]=i;
		dfs(dep+1);
		use[i]=0;pd[rk[dep]]=-1;
	}	
}
signed main()
{
	read(n);
	memset(num,-1,sizeof(num));
	for(i=1;i<=n;i++){
		string tmp;cin>>tmp;
		st.insert(tmp);
	}
	n=0;
	for(set<string>::iterator it=st.begin();it!=st.end();it++){
		string sr=*it;
		len[++n]=sr.length();
		memset(pd,0,sizeof(pd));
		for(j=1;j<=len[n];j++){
			if(sr[j-1]-'a'>12){
				puts("noway");
				exit(0);
			}
			num[n][j]=sr[j-1]-'a',pd[sr[j-1]-'a']=1;
		}
		for(j=0;j<=12;j++)
		cnt[j]+=pd[j];
	}
	for(ie=0;ie<=12;ie++){
		if(cnt[ie]!=n)continue;
		for(im=0;im<=12;im++)if(im!=ie)
		for(ia=0;ia<=12;ia++)if(ia!=im&&ia!=ie)
		for(i0=0;i0<=12;i0++)if(i0!=ia&&i0!=ie&&i0!=im){
			memset(pd,-1,sizeof(pd));
			memset(mid,0,sizeof(mid));
			int ctt[15];memset(ctt,0,sizeof(ctt));
			int sm=0,now=0;sol=0;fg=0;
			pd[ie]=10,pd[ia]=11,pd[im]=12,pd[i0]=0;
			for(i=1;i<=n;i++){
				for(j=1;j<=len[i];j++){
					if(num[i][j]==ie&&mid[i])break;
					if(num[i][j]==ie)mid[i]=j;
					if(isn(num[i][j])){
						if(num[i][j]==i0&&isn(num[i][j+1])&&!isn(num[i][j-1]))break;
						ctt[num[i][j]]=1;
					}
					else{
						if(num[i][j]==ie&&(!isn(num[i][j+1])||!isn(num[i][j-1])))break;
						if(num[i][j]!=ie&&(!isn(num[i][j+1])||!isn(num[i][j-1])))break;
					}
				}
				if(j!=len[i]+1)break;int tp=0;
				for(j=1;j<=9;j++)tp+=ctt[j];
				if(tp<sm&&tp>=6){
					swap(num[1],num[i]);
					swap(len[1],len[i]);
				}
			}
			if(i!=n+1)continue;
			int es[15];memset(es,0,sizeof(es));now=0;
			for(i=1;i<=len[1];i++){
				if(!isn(num[1][i])||es[num[1][i]]||num[1][i]==0)continue;
				rk[++now]=num[1][i],es[num[1][i]]=1;
			}
			fr=now;
			for(i=0;i<=12;i++){
				if(!isn(i)||i==i0||es[i])continue;
				rk[++now]=i;
			}	
			for(i=1;i<=n;i++){
				int p1=get(num[i],1,mid[i]-1),p2=get(num[i],mid[i]+1,len[i]);
				if(p1==0&&p2||p2==0&&p1)break;
			}
			if(i!=n+1){
				continue;
			}
			dfs(0);
		}
	}
	for(i=0;i<=12;i++)
	for(j=0;j<=12;j++){
		cnt_a[i]+=ass[i][j];
	}
	for(i=0;i<=12;i++){
		if(cnt_a[i]!=1)continue;
		for(j=0;j<=12;j++)
		if(ass[i][j])
		printf("%c%c\n",'a'+i,as[j]);
	}
	if(!ok)printf("noway\n");
//	cout<<sol<<endl;
//	cout<<s<<' '<<t<<endl;
	return 0;
}
