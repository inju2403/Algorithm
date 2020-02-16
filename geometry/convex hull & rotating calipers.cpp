struct node {
	ll x,y;
	int dx,dy;
	bool operator <(const node& arg) const {
		return x==arg.x? y<arg.y : x<arg.x;
	}
};
vector<node> a,CH;

//Singed Area
ll SA(node a,node b,node c) {
	return (a.x*b.y-a.y*b.x)+(b.x*c.y-b.y*c.x)+(c.x*a.y-c.y*a.x); 
}

int ccw(node a, node b, node c) {
	ll d = (a.x*b.y-a.y*b.x) + (b.x*c.y-b.y*c.x) + (c.x*a.y-c.y*a.x);
    if(d == 0) return 0;
    return d>0? 1:-1;
}

ll dist(node a, node b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

vector<node> getCH(vector<node>& a) {
	//기준점 찾기
	swap(a[0],*min_element(a.begin(),a.end()));
	//기준점으로 부터 반시계 방향으로 정렬 
	sort(a.begin()+1,a.end(),[&](const node &b, const node &c) {
		if(ccw(a[0],b,c) != 0) {
			return ccw(a[0],b,c) > 0;
		}
	    else if(ccw(a[0],b,c) == 0) {
		    return dist(a[0],b) < dist(a[0],c);
	    }
	});
	
	vector<node> CH;
	CH.push_back(a[0]);
	for(int i=1; i<a.size(); ++i) {
		while(CH.size()>=2&&ccw(CH[CH.size()-2],CH.back(),a[i])<=0) {
			CH.pop_back();
		}
		CH.push_back(a[i]);
	}
	return CH;
}


pii rotatingCalipers(vector<node>& CH) {
	int h=CH.size();
	int j=1;
	pii pairs;
	ll mxDist=0;
	FOR(i,h) {
        if(mxDist < dist(CH[i],CH[j])) {
			mxDist=dist(CH[i],CH[j]);
			pairs={i,j};
		}
		while(j+1<h && SA(CH[i],CH[i+1],CH[j]) <= SA(CH[i],CH[i+1],CH[j+1])) {
            j=j+1;     
            if(mxDist < dist(CH[i],CH[j])) {
				mxDist=dist(CH[i],CH[j]);
				pairs={i,j};
			}
		}
	}
	return pairs;
}
