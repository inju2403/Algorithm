#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
#include<numeric>
#include<ctime>
#include<tuple>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define INF 1987654321
#define MAX 17
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<vector<int> > vii;

int n,cache[MAX][1<<MAX],dist[MAX][MAX];

int tsp(int here,int visited) {
	if(visited == (1<<n)-1) return dist[here][0]==0? INF : dist[here][0];
	
	int& ret = cache[here][visited];
	if(ret != -1) return ret;
	ret=INF;
	FOR(next,n) {
		if(visited & (1<<next)) continue;
		if(dist[here][next]==0) continue;
		ret = min(ret,tsp(next,visited | (1<<next))+dist[here][next]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(cache,-1,sizeof(cache));
	cin>>n;
	FOR(i,n) FOR(j,n) cin>>dist[i][j];
	cout<<tsp(0,1);
}
