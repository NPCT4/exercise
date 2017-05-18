#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2000100;
const int INF=1e9+10;

int n,q;
int a[maxn];
int u,v;
vector<int> G[maxn];
int op,x,w;
int f[maxn],pos[maxn];
int dep[maxn];
vector<int> prime;
bool isprime[maxn];

void getPrime(){
	memset(isprime,1,sizeof(isprime));
	isprime[1]=0;
	for(int i=2;i<maxn;i++){
		if(isprime[i]==0) continue;
		for(int j=i+i;j<maxn;j+=i) isprime[j]=0;
	}
	for(int i=2;i<maxn;i++) if(isprime[i]) prime.push_back(i);
}

void get_dep(int u,int fa,int d){
	dep[u]=d;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==fa) continue;
		get_dep(v,u,d+1);
	}
}

void dfs(int u,int fa){
	int N=a[u];
	vector<int> X,Y;
	for(int i=0;i<prime.size();i++){
		int t=prime[i];
		if(t*t>N) break;
		if(N%t==0){
			if(~pos[t]&&(f[u]==-1||dep[pos[t]]>dep[f[u]])) f[u]=pos[t];
			X.push_back(t);
			Y.push_back(pos[t]);
			pos[t]=u;
			while(N%t==0) N/=t;
		}
	}
	if(N!=1){
		int t=N;
		if(~pos[t]&&(f[u]==-1||dep[pos[t]]>dep[f[u]])) f[u]=pos[t];
		X.push_back(t);
		Y.push_back(pos[t]);
		pos[t]=u;
	}
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
	for(int i=0;i<X.size();i++){
		int t=X[i],p=Y[i];
		pos[t]=p;
	}
}

void build(){
	memset(f,-1,sizeof(f));
	memset(pos,-1,sizeof(pos));
	dfs(1,0);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	getPrime();
	while(cin>>n>>q){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),G[i].clear();
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		get_dep(1,0,1);
		build();
		for(int i=1;i<=q;i++){
			scanf("%d%d",&op,&x);
			if(op==1) printf("%d\n",f[x]);
			else{
				scanf("%d",&w);
				a[x]=w;
				build();
			}
		}
	}
	return 0;
}

