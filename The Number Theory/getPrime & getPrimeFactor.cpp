#define MAX 500000

bool s[MAX+1];
vector<int> prime;

void getPrime() {
	for(int i=2; i<=MAX; ++i) s[i]=1;
	for(int i=2; i*i<MAX; ++i) {
		if (s[i] == 0) continue;
		for (int j = i * i; j <= MAX; j += i) {
			s[j] = 0;
		}
	}
	for(int i=2; i<=MAX; ++i) if(s[i]) prime.push_back(i);
}


// 소인수 분해 
int n,minFactor[MAX+1];

void getPrime2(int n) {
	for(int i=2; i<=n; ++i) minFactor[i]=i;
	for(int i=2; i*i<=n; ++i) {
		if (minFactor[i] == i)
		for (int j = i * i; j <= MAX; j += i) {
			//아직 약수를 본 적 없는 숫자인 경우에 갱신
			if(minFactor[j] == j) 
				minFactor[j] = i;
		}
	}
}

vector<int> factor(int n) {
	vector<int> ret;
	while(n>1) {
		int num = minFactor[n];
		ret.push_back(num);
		n/=num;
	}
	return ret;
}
