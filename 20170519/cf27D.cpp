#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,m;
struct Edge{
	int x,y;
	int id;
};Edge e[maxn];
int ans[maxn];
vector<int> G[maxn];

bool intersect(Edge A,Edge B){
	if(A.x>A.y) swap(A.x,A.y);
	if(B.x>B.y) swap(B.x,B.y);
	if(A.x<B.x&&B.x<A.y&&A.y<B.y) return 1;
	if(B.x<A.x&&A.x<B.y&&B.y<A.y) return 1;
	return 0;
}

bool dfs(int u,int c){
	if(~ans[u]) return ans[u]==c;
	ans[u]=c;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(!dfs(v,c^1)) return 0;
	}
	return 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>m){
		for(int i=1;i<=m;i++) scanf("%d%d",&e[i].x,&e[i].y),e[i].id=i;
		for(int i=1;i<=m;i++) G[i].clear(),ans[i]=-1;
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				int u=e[i].id,v=e[j].id;
				if(intersect(e[i],e[j])){
					G[u].push_back(v);
					G[v].push_back(u);
				}
			}
		}
		bool flag=1;
		for(int i=1;i<=m;i++){
			if(ans[i]==-1&&!dfs(i,1)){
				flag=0;break;
			}
		}
		if(flag){
			for(int i=1;i<=m;i++) printf("%c",ans[i]?'i':'o');puts("");
		}
		else puts("Impossible");
	}
	return 0;
}


