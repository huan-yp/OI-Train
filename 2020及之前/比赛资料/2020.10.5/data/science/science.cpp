#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define fi firsts
#define se second
#define mk make_pair
#define pb push_back

#define N 200005
#define M 1000000007
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,q,pos[N],dir[N],ta,tb,ID,T;
struct Node{int id,pos;}l[N],r[N];
inline bool cmp(Node a,Node b)
{
		 return a.pos<b.pos;
}
int work()
{
		int fin;
		if (dir[ID]==-1)
		{
				int now=lower_bound(l+1,l+ta+1,(Node){0,pos[ID]},cmp)-l; 
				int rnow=lower_bound(r+1,r+tb+1,(Node){0,pos[ID]},cmp)-r;
				--rnow;
				if (!rnow||l[now].pos-r[rnow].pos>T*2) fin=ID;
				else 
				{
						int L=1,R=min(ta-now+1,rnow)+1,mid=0;
						while ((L+R)>>1!=mid)
						{
								mid=(L+R)>>1;
								if (l[now+mid-1].pos-r[rnow-mid+1].pos<=T*2) L=mid; else R=mid; 
						}
						if (now+L<=ta&&l[now+L].pos-r[rnow-L+1].pos<=T*2) fin=l[now+L].id;
						else fin=r[rnow-L+1].id;
				}
		}
		else 
		{
				int now=lower_bound(r+1,r+tb+1,(Node){0,pos[ID]},cmp)-r;
				int lnow=lower_bound(l+1,l+ta+1,(Node){0,pos[ID]},cmp)-l;
				if (lnow>ta||l[lnow].pos-r[now].pos>T*2) fin=ID;
				else 
				{
						int L=1,R=min(ta-lnow+1,now)+1,mid=0;
						while ((L+R)>>1!=mid)
						{
								mid=(L+R)>>1;
								if (l[lnow+mid-1].pos-r[now-mid+1].pos<=T*2) L=mid; else R=mid;
						}
						if (L!=now&&l[lnow+L-1].pos-r[now-L].pos<=T*2) fin=r[now-L].id;
						else fin=l[lnow+L-1].id;
				}
		}
		return abs(pos[fin]+dir[fin]*T);
}
char c[N];
inline int read(){
		int x,f=0; char c;
		while (c=getchar(),(c<'0'||c>'9')&&c!='-');
		if (c=='-') f=1,c=getchar();
		x=c-'0';
		while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
		if (f) return -x; 
		return x;
}
class FindingKids{
	public:
		long long getSum()
		{
			n=read(); q=read();
			for (i=0;i<n;++i) pos[i]=read();
			scanf("%s",c);
			for (i=0;i<n;++i)
			{
    		    if (c[i]=='L') dir[i]=-1,l[++ta]=(Node){i,pos[i]};
    		    else dir[i]=1,r[++tb]=(Node){i,pos[i]}; 
			}
			sort(l+1,l+ta+1,cmp);
			sort(r+1,r+tb+1,cmp);
			long long ans=0;
			for (;q--;)
    		{
				ID=read(); T=read();
				--ID;
				printf("%d\n",work());
			}
			return ans;
		}
}MRT;

int main()
{
	 freopen("science10.in","r",stdin);
	 freopen("science10.out","w",stdout); 
	 MRT.getSum();
}

