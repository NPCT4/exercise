#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n;
int c,s;
pair<int,int> p[2][maxn];int pn[2];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n){
		pn[0]=pn[1]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&c,&s);
			p[c][pn[c]++]=make_pair(s,i);
		}
		sort(p[0],p[0]+pn[0]);
		sort(p[1],p[1]+pn[1]);
		for(int i=0,j=0;i<pn[0]&&j<pn[1];){
			if(p[0][i].first<p[1][j].first){
				printf("%d %d %d\n",
					p[0][i].second,p[1][j].second,p[0][i].first);
				p[1][j].first-=p[0][i].first;
				p[0][i].first=0;
				i++;
			}
			else if(p[0][i].first>p[1][j].first){
				printf("%d %d %d\n",
					p[0][i].second,p[1][j].second,p[1][j].first);
				p[0][i].first-=p[1][j].first;
				p[1][j].first=0;
				j++;
			}
			else{
				printf("%d %d %d\n",
					p[0][i].second,p[1][j].second,p[0][i].first);
				p[0][i].first=p[1][j].first=0;
				if(i+1<pn[0]) i++;
				else j++;
			}
		}
	}
	return 0;
}
