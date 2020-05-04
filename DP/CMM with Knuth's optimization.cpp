#include<iostream>
#include<vector>
#include<algorithm>
#define INF 987654321
#define MAX 5005
using namespace std;

// p[i][j]: ?d[i][j]가 최소가 되기 위한 가장 작은 k

int tc,n,d[MAX][MAX],p[MAX][MAX];
vector<int> v,sum;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>tc;
	while(tc--) {
		cin>>n;
		v.clear(); v.resize(n+1,0);
		sum.clear(); sum.resize(n+1,0);
		for(int i=1; i<=n; ++i) {
			cin>>v[i];                    //v[i]: i 번째 파일의 크기
            sum[i] += sum[i-1] + v[i];    //sum[i]: i 번째 파일까지 파일의 크기들의 합
			p[i-1][i]=i;                  //p[i-1][i]값을 i로 설정		
        } 
		for(int i=n-1;i>=1;--i) {
            for(int j=i+2; j<=n; ++j) {  //j는 i+2부터 시작
                d[i][j] = INF;
			    for(int k = p[i][j-1]; k <= p[i+1][j]; ++k) {
					int val=d[i][k]+d[k][j];
					if(d[i][j]>val) {
				        p[i][j]=k;    //?p[i][j]를 d[i][j]가 최소가 되기 위한 가장 작은 k로 갱신
					    d[i][j]=val;
					}	
				}
				d[i][j]+=sum[j]-sum[i];    // 계산이 중복되므로 for문이 끝나고 계산
		    }
		}
		cout<<d[0][n]<<'\n';
	}
}
