#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int N,K;
char ch[1200][1200];int id[1200][1200];int idn;
int fa[maxn],cnt[maxn];
int res;

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int work(int a,int b){
	int c=a+K-1,d=b+K-1;
	set<int> s;
	int tmp=0;
	if(a>1){
		for(int i=b;i<=d;i++){
			if(ch[a-1][i]=='X') continue;
			int x=find(id[a-1][i]);
			if(s.find(x)!=s.end()) continue;
			s.insert(x);
			tmp+=cnt[x];
		}
	}
	if(c<N){
		for(int i=b;i<=d;i++){
			if(ch[c+1][i]=='X') continue;
			int x=find(id[c+1][i]);
			if(s.find(x)!=s.end()) continue;
			s.insert(x);
			tmp+=cnt[x];
		}
	}
	if(b>1){
		for(int i=a;i<=c;i++){
			if(ch[i][b-1]=='X') continue;
			int x=find(id[i][b-1]);
			if(s.find(x)!=s.end()) continue;
			s.insert(x);
			tmp+=cnt[x];
		}
	}
	if(d<N){
		for(int i=a;i<=c;i++){
			if(ch[i][d+1]=='X') continue;
			int x=find(id[i][d+1]);
			if(s.find(x)!=s.end()) continue;
			s.insert(x);
			tmp+=cnt[x];
		}
	}
	if(tmp+K*K<=res) return res;
	for(int i=a;i<=c;i++){
		for(int j=b;j<=d;j++){
			if(ch[i][j]=='X') tmp++;
			else{
				int x=find(id[i][j]);
				if(s.find(x)!=s.end()) continue;
				s.insert(x);
				tmp+=cnt[x];
			}
		}
	}
	return tmp;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>N>>K){
		idn=0;
		for(int i=1;i<=N;i++){
			scanf("%s",ch[i]+1);
			for(int j=1;j<=N;j++){
				if(ch[i][j]=='.') id[i][j]=++idn,fa[idn]=idn,cnt[idn]=1;
			}
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(ch[i][j]=='X') continue;
				for(int k=0;k<4;k++){
					int nx=i+dx[k],ny=j+dy[k];
					if(nx<1||nx>N||ny<1||ny>N||ch[nx][ny]=='X') continue;
					int u=id[i][j],v=id[nx][ny];
					int xx=find(u),yy=find(v);
					if(xx==yy) continue;
					fa[xx]=yy;
					cnt[yy]+=cnt[xx];
					cnt[xx]=0;
				}
			}
		}
		res=0;
		for(int i=1;i<=idn;i++) res=max(res,cnt[find(i)]);
		for(int i=1;i<=N-K+1;i++){
			for(int j=1;j<=N-K+1;j++){
				res=max(res,work(i,j));
			}
		}
		cout<<res<<endl;
	}
	return 0;
}


/*

5 2
..XXX
XX.XX
X.XXX
X...X
XXXX.

5 3
.....
.XXX.
.XXX.
.XXX.
.....

4 2 
XXX.
XXXX
X.XX
XXXX

3 1
X..
XX.
.XX
*/
