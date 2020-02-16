#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX_V 105
using namespace std;
typedef long long ll;

int V,m;
int adj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];

void floyd() {
	memset(via,-1,sizeof(via));
	FORS(i,1,V+1) adj[i][i]=0;
	
	FORS(k,1,V+1) FORS(i,1,V+1) FORS(j,1,V+1) {
		if(adj[i][j]>adj[i][k]+adj[k][j]) {
			via[i][j]=k;
			adj[i][j]=adj[i][k]+adj[k][j];
		}
	}
}

void path(int q,int r) {
	if(via[q][r]!=-1) {
		path(q,via[q][r]);
		cout<<via[q][r]<<" ";
		path(via[q][r],r);
	}
}

int main() {
	cin>>V>>m;
	FORS(i,1,V+1) FORS(j,1,V+1) adj[i][j]=INF;
	while(m--) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(adj[u][v]>w) adj[u][v]=w;
	}
	floyd();
} 
