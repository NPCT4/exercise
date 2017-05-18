#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int N,K;
char ch[520][520];
int id[520][520],cnt[maxn],idn;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int in[maxn];
bool border[maxn];
vector<int> tb;

void dfs(int i,int j,int color){
	if(i<1||i>N||j<1||j>N||ch[i][j]=='X'||id[i][j]) return;
	id[i][j]=color;
	for(int k=0;k<4;k++) dfs(i+dx[k],j+dy[k],color);
}

int Add(int x,int out){
	if(x==0) return out==0;
	if(in[x]) return 0;
	in[x]=1;
	return cnt[x];
}

void add_border(int x){
	if(x==0) return;
	in[x]=1;
	if(border[x]) return;
	border[x]=1;
	tb.push_back(x);
}

int Del(int x){
	if(x==0) return 0;
	if(border[x]) return 0;
	in[x]=0;
	return -cnt[x];
}

int work(int a){
	int c=a+K-1;
	for(int i=1;i<=idn;i++) in[i]=0;
	int tmp=0;
	int res=K*K;
	for(int i=a-1;i<=c+1;i++){
		if(i<1||i>N) continue;
		for(int j=1;j<=K+1;j++){
			if(j<1||j>N) continue;
			if(i==a-1&&j==K+1||i==c+1&&j==K+1) continue;
			int out=0;
			if(i<a||i>c||j<1||j>K) out=1;
			tmp+=Add(id[i][j],out);
		}
	}
	res=max(res,tmp);
	set<int> s;
	for(int i=1;i<=idn;i++) border[i]=0;
	for(int b=1;b+K-1<N;b++){
		int d=b+K-1;
		// build border
		tb.clear();
		for(int i=a;i<=c;i++){
			add_border(id[i][b]);
			if(d+1<=N) add_border(id[i][d+1]);
		}
		for(int i=b+1;i<=d;i++){
			if(a-1>=1) add_border(id[a-1][i]);
			if(c+1<=N) add_border(id[c+1][i]);
		}
		// del left
		s.clear();
		for(int i=a;i<=c;i++){
			if(b-1<1) break;
			s.insert(id[i][b-1]);
		}
		if(a-1>=1) s.insert(id[a-1][b]);
		if(c+1<=N) s.insert(id[c+1][b]);
		for(set<int>::iterator it=s.begin();it!=s.end();++it) tmp+=Del(*it);
		for(int i=a;i<=c;i++) if(id[i][b]==0) tmp--;
		// add right
		s.clear();
		for(int i=a;i<=c;i++){
			if(d+2>N) break;
			s.insert(id[i][d+2]);
		}
		if(a-1>=1&&d+1<=N) s.insert(id[a-1][d+1]);
		if(c+1<=N&&d+1<=N) s.insert(id[c+1][d+1]);
		for(set<int>::iterator it=s.begin();it!=s.end();++it)
			tmp+=Add(*it,1);
		for(int i=a;i<=c;i++) if(d+1<=N&&id[i][d+1]==0) tmp++;
		// cal
		res=max(res,tmp);
		for(int i=0;i<tb.size();i++) border[tb[i]]=0;
	}
	return res;
}

int solve(){
	int res=K*K;
	for(int a=1;a+K-1<=N;a++) res=max(res,work(a));
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>N>>K){
		for(int i=1;i<=N;i++) scanf("%s",ch[i]+1);
		idn=0;
		for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) id[i][j]=0;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(ch[i][j]=='X'||id[i][j]) continue;
				dfs(i,j,++idn);
			}
		}
		for(int i=1;i<=idn;i++) cnt[i]=0;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(ch[i][j]=='X') continue;
				cnt[id[i][j]]++;
			}
		}
		printf("%d\n",solve());
	}
	return 0;
}

