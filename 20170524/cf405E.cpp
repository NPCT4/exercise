#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,m;
int u,v;
bool vis[maxn];
struct Edge{
	int v;
};Edge e[maxn];int en;
int head[maxn],nex[maxn];

void addedge(int u,int v){
	e[en].v=v;
	nex[en]=head[u];
	head[u]=en;
	en++;
}

int dfs(int u,int f){
	int p[2],pn=0;
	for(int i=head[u];~i;i=nex[i]){
		int v=e[i].v;
		if(v==f) continue;
		if(vis[i]||vis[i^1]) continue;
		vis[i]=vis[i^1]=1;
		int r=dfs(v,u);
		if(r) printf("%d %d %d\n",u,v,r);
		else p[pn++]=v;
		if(pn==2) printf("%d %d %d\n",p[0],u,p[1]),pn=0;
	}
	return pn?p[0]:0;
}

void solve(){
	if(m%2){
		puts("No solution");
		return;
	}
	memset(vis,0,sizeof(vis));
	dfs(1,0);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>m){
		memset(head,-1,sizeof(head));
		memset(nex,-1,sizeof(nex));
		en=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		solve();
	}
	return 0;
}

