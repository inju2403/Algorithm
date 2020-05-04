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
#define INF 2147483647
#define MAX 505
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<vector<int> > vii;

int n,R[MAX][MAX];
double d[MAX][MAX],p[MAX],sum[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	FORS(i,1,n+1) cin>>p[i],sum[i]=p[i];
	FORS(i,2,n+2) sum[i]+=sum[i-1];
	FORS(i,1,n+2) d[i][i]=p[i], R[i][i]=i;
	for(int diagonal=1; diagonal<=n-1; ++diagonal) {
	    for(int i=1; i<=n-diagonal; ++i) {
	        int j=i+diagonal;
			for(int k=i; k<=j; ++k) {
				if(d[i][j]==0) {
					d[i][j]=d[i][k-1]+d[k+1][j]+sum[j]-sum[i-1];
					R[i][j]=k;
				}
				else if(d[i][j]>d[i][k-1]+d[k+1][j]+sum[j]-sum[i-1]) {
					d[i][j]=d[i][k-1]+d[k+1][j]+sum[j]-sum[i-1];
					R[i][j]=k;
				}
	    	}
		}
	}
	
	FORS(i,1,n+2)  {
		FORS(j,0,n+1) {
			if(d[i][j]!=INF) cout<<d[i][j]<<"\t";
			else cout<<0<<"\t";
		}
		cout<<'\n';
	}
	cout<<endl;
	FORS(i,1,n+2)  {
		FORS(j,0,n+1) {
			cout<<R[i][j]<<"\t";
		}
		cout<<'\n';
	}
	cout<<endl;
	
}
