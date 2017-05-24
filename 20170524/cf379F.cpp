#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,m;
vector<int> G[maxn];
int dp[maxn][20];
int dep[maxn];
int u,v;
int A,B;

int dfs(int u,int t){
	int &res=dp[u][t];
	if(~res) return res;
	if(u==1) return res=0;
	int f=dfs(u,t-1);
	if(f==0) return res=0;
	return res=dfs(f,t-1);
}

int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int st=0;
	while((1<<st)<=dep[u]) st++;
	st--;
	for(int i=st;i>=0;i--){
		if(dfs(u,i)&&dep[dfs(u,i)]>=dep[v]) u=dfs(u,i);
	}
	if(u==v) return u;
	while(st>=0){
		if(dfs(u,st)&&dfs(u,st)!=dfs(v,st)){
			u=dfs(u,st);
			v=dfs(v,st);
		}
		st--;
	}
	return dfs(u,0);
}

void init(){
	n=4;
	for(int i=2;i<=4;i++) G[1].push_back(i),dep[i]=1;
	dep[1]=0;
	A=2;B=3;
	dp[1][0]=0;
	for(int i=2;i<=4;i++) dp[i][0]=1;
} 

void add(int u,int v){
	G[u].push_back(v);
	dep[v]=dep[u]+1;
	dp[v][0]=u;
	int x=dep[A]+dep[B]-2*dep[lca(A,B)];
	int y=dep[A]+dep[v]-2*dep[lca(A,v)]; 
	int z=dep[B]+dep[v]-2*dep[lca(B,v)];
	if(x>=y&&x>=z) return;
	if(y>=x&&y>=z){
		B=v;return;
	}
	if(z>=x&&z>=y){
		A=v;return;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>m){
		for(int i=0;i<maxn;i++) G[i].clear();
		memset(dp,-1,sizeof(dp));
		init();
		while(m--){
			scanf("%d",&u);
			add(u,++n);
			add(u,++n);
			printf("%d\n",dep[A]+dep[B]-2*dep[lca(A,B)]);
		}
	}
	return 0;
}
		
