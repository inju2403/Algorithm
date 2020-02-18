long long res;
vector<int> a, tmp;

void merge(int l,int mid,int r) {
	int i=l;
	int j=mid+1;
	int k=l;
	
	while(i<=mid && j<=r) {
		if(a[i]<=a[j]) {
			tmp[k++]=a[i++];	
		}
		else {
			tmp[k++]=a[j++];
			res+=mid-(i-1);	   // swap이 일어날 횟수
		}
	}
	
    while(j<=r) tmp[k++]=a[j++];
	while(i<=mid) tmp[k++]=a[i++];
	
	for(int idx=l; idx<=r; ++idx) a[idx]=tmp[idx];
}


void mergeSort(int l,int r) {
	if(l<r) {
		int mid=(l+r)/2;
		mergeSort(l,mid);
		mergeSort(mid+1,r);
		merge(l,mid,r);
	}
}
