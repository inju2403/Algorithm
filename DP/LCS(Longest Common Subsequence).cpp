#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 1005
using namespace std;

int d[MAX][MAX],i,j;
bool c[MAX][MAX];
string a,b;
vector<char> v;

int main() {
	cin>>a>>b;
	int x=a.length();
	int y=b.length();
	FORS(i,1,x+1) FORS(j,1,y+1) {
		d[i][j]=max({d[i-1][j],d[i][j-1],d[i-1][j-1]+(a[i-1]==b[j-1])});
	}
	cout<<d[x][y]<<'\n';
	while(d[x][y]) {
		if(d[x][y]==d[x-1][y]) --x;
		else if(d[x][y]==d[x][y-1]) --y;
		else {
			v.push_back(a[x-1]);
			--x,--y;
		}
	}
	reverse(v.begin(),v.end());
	FOR(i,v.size()) cout<<v[i];
}
