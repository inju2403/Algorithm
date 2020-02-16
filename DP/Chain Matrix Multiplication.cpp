//diagnal 
for(int diagonal=1; diagonal<n; ++diagonal) {
    for(int i=0; i<n-diagonal; ++i) {
        int j=i+diagonal;
		for(int k=i; k<j; ++k) {
			d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]+r[i]*c[k]*c[j]);
        }
	}
}

//Move right as move up
for(int i=n-2;i>=0;--i) {
    for(int j=i+1; j<n; ++j) {
        for(int k=i; k<j; ++k) {
		    d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]+r[i]*c[k]*c[j]);
        }
	}
}


//memoization
// 메인함수에서 cache배열을 -1로 초기화

int dp(int a, int b) {
	if (a == b) return 0;
	
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	
	mn = INF;
	for (int k = a; k < b; ++k) {
		mn = min(mn, dp(a, k) + dp(k + 1, b) + r[a] * c[k] * c[b]);
	}
	return ret = mn;
}
