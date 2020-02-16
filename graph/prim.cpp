#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 987654321
using namespace std;
typedef pair<int,int> pii;

int V,E,u,v,w,res;
bool visited[10005];
vector<pii> adj[10005];
vector<pii> tree;

void prim(int start){
	visited[start]=true;
	priority_queue<pair<int,pii> > pq;
	for(auto next : adj[start]) {
		int there = next.first;
		int nextCost = -next.second;
		
		pq.push({nextCost,{start,there}});
	}
	
	while(!pq.empty()) {
		int pre = pq.top().second.first;
		int here = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();
		if(visited[here]) continue;
		
		visited[here]=true;
		res+=cost;
		tree.push_back({pre,here});
		
		for(auto next : adj[here]) {
			int there = next.first;
			int nextCost = -next.second;
		
			pq.push({nextCost,{here,there}});
		}
	}
	cout<<res<<'\n';
	for(int i=0;i<tree.size();++i) {
		cout<<tree[i].first<<" "<<tree[i].second<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>V>>E;
	while(E--) {
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	prim(1);
}
