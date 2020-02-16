const int MAX = 1e5+10;
const int k = 17; // 2^17 > 10만
int par[MAX][18],visited[MAX],d[MAX];
vertor<int> adj[MAX];

void DFS(int here,int depth) {
	visited[here]=true;
	d[here]=depth;
	for(auto there : adj[here]) {
		if(visited[there]) continue; 
		par[there][0]=here;
		DFS(there,depth+1);
	}
}

void SetLCA() {
    for(int j=1;j<=k;++j) {
    	for(int i=1;i<=n;++i) {
    		par[i][j]=par[par[i][j-1]][j-1];
		}
	}
}

int LCA(int u,int v) {
	if(d[u] < d[v]) swap(u,v);
	// 두 정점의 깊이를 맞춘다
	for(int i=k; i>=0; --i) {
		if(d[u]-d[v] >= (1<<i))
			u=par[u][i];
	}
	// 깊이를 맞췄을 때 두 정점이 같아진다면 정점 자체가 LCA 
	if(u==v) return u;
	//두 정점의 조상을 비교한다 
	for(int i=k; i>=0; --i) {
		if(par[u][i] != par[v][i]) {
			u=par[u][i], v=par[v][i];
		}
	}
	//두 정점중 한 정점의 부모를 리턴한다 
	return par[u][0];
}
