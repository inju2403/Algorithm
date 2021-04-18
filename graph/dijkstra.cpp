#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 987654321
#define MAX 1001
using namespace std;
typedef pair<int,int> pii;

int n,m,src,sink,u,v,w;
vector<int> route,path;
vector<pii> adj[MAX];

int dijkstra(int src,int sink) {
    vector<int> dist(n+1,INF);
    route.resize(n+1);
    
    dist[src]=0;
    priority_queue<pii> pq;
    pq.push({0,src});
    
    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(cost > dist[here]) continue;
        
        for(auto next: adj[here]) {
            int there = next.second;
            int nextCost = cost + next.first;
            if(dist[there] > nextCost) {
		// route: there로 최소비용으로 가기 위해 here을 거친다
                route[there]=here;
                dist[there] = nextCost;
                pq.push({-nextCost,there});
            }
        }
    }
	
    //sink부터 거슬러 올라가 path를 구한다. path를 거꾸로 출력하면 src -> sink 최소비용 경로
    int via = sink;
    while(via) {
        path.push_back(via);
        via = route[via];
    }
    
    return dist[sink];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    while(m--) {
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }
    cin>>src>>sink;
    cout<<dijkstra(src,sink)<<'\n'<<path.size()<<'\n';
    for(int i=path.size()-1; i>=0; --i) cout<<path[i]<<" ";
}
