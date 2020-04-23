string bigAdd(string s1,string s2) {
	int sum=0;
	string res="";
	
	while(!s1.empty() || !s2.empty() || sum) {
		if(!s1.empty()) {
			sum+=s1.back()-'0';
			s1.pop_back();
		}
		if(!s2.empty()) {
			sum+=s2.back()-'0';
			s2.pop_back();
		}
		res.push_back(sum%10+'0');
		sum/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
