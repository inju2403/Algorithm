#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORS(i,s,n) for(int i=(s);i<(n);++i)
#define MAX 4010
using namespace std;


// 2차원 배열 1개 
int res,d[MAX][MAX];
string a,b;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>a>>b;
	int x=a.size();
	int y=b.size();
	FORS(i,1,x+1) FORS(j,1,y+1) {
		if(a[i-1]==b[j-1]) {
			d[i][j]=d[i-1][j-1]+1;
		}
	}
	FORS(i,1,x+1) FORS(j,1,y+1) res=max(res,d[i][j]);
	cout<<res;
	return 0;
}



// 1차원 배열 2개
int res,A[MAX],B[MAX];
string a,b;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>a>>b;
	int x=a.size();
	int y=b.size();
	//1차원 배열 2개
	FORS(i,1,x+1) {	
		FORS(j,1,y+1) {
			if(a[i-1]==b[j-1]) {
				A[j]=B[j-1]+1;
				res=max(res,A[j]);
			}
		}
		FORS(j,1,y+1) B[j]=A[j];
		memset(A,0,sizeof(A));
	}
	cout<<res;
	return 0;
}
