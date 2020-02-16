#define INF 987654321
vector<pair<int,int>> adj[10000]; //cost,V

void bellmanFord() {
	vector<int> upper(n,INF);
	upper[0]=0;
	bool updated=0;
	int k=n;

	while(k--) {
		updated=0;
		for(int here=0; here<upper.size(); ++here) {
			for(auto next : adj[here]) {
				int there = next.second;
				int nextDist = next.first;
				
				if (upper[here]!=INF && upper[there] > upper[here] + nextDist) {
	                upper[there] = upper[here] + nextDist;
	                updated = true;
	            }
			}
		}
	}
	if(!updated) {
		if(upper[n*m-1]==INF) cout<<"Impossible\n";
		else cout<<upper[n*m-1]<<'\n';
	}
	else cout<<"Never\n";
}
