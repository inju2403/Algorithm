#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 987654321
using namespace std;
typedef pair<int,int> pii;

int V,E,st,u,v,w;
vector<pair<int,int> > adj[20005];

vector<int> dijkstra(int start) {
	vector<int> dist(V+1,INF);
	dist[start]=0;
	priority_queue<pii> pq;
	pq.push({0,st});
	while(!pq.empty()) {
		pii cur=pq.top(); pq.pop();
		int here = cur.second;
		int cost = -cur.first;
		if(dist[here]<cost) continue;
		
		for(auto next: adj[here]) {
			int there = next.first;
			int nextCost = cost+next.second;
			if(dist[there]>nextCost) {
				dist[there]=nextCost;
				pq.push({-nextCost,there});
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>V>>E>>st;
	while(E--) {
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	vector<int> dist=dijkstra(st);
}
