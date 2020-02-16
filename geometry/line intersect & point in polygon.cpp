#define FOR(i,n) for(int i=0;i<(n);++i)

struct NODE{
	ll x,y;
	bool operator<(const NODE& arg) const {
		return x==arg.x?y<arg.y:x<arg.x;
	}
	bool operator<=(const NODE& arg) const {
		if(x==arg.x && y==arg.y) return true;
		return x==arg.x?y<arg.y:x<arg.x;
	} 
};

int ccw(NODE a,NODE b,NODE c) {
	ll d = (a.x*b.y-a.y*b.x)+(b.x*c.y-b.y*c.x)+(c.x*a.y-c.y*a.x); 
	if(d==0) return 0;
	return d>0? 1:-1;
}

bool isIntersect(NODE a,NODE b,NODE c,NODE d) {
	int x=ccw(a,b,c)*ccw(a,b,d),y=ccw(c,d,a)*ccw(c,d,b);
	if(x==0&&y==0) {
		if(b<a) swap(a,b);
		if(d<c) swap(c,d);
		return a<=d&&c<=b;
	}
	return x<=0&&y<=0;
}

bool isInPolygon(NODE b,vector<NODE> &c) {
	int CrossCnt=0;
	vector<pair<double,double>> v;
	FOR(i,c.size()) v.push_back({c[i].x,c[i].y});
	pair<double,double> a={b.x,b.y};
	FOR(i,v.size()) {
		int j=(i+1)%v.size();
		if((v[i].second>a.second) != (v[j].second>a.second)) {
			double X=(v[j].first-v[i].first)*(a.second-v[i].second)/(v[j].second-v[i].second)+v[i].first;
			if(a.first<X) ++CrossCnt;
		}
	}
	return CrossCnt%2>0;
}
