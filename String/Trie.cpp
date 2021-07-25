struct Trie {
	bool finish;
	Trie* children[26];
	Trie() : finish(false) {
		memset(children,0,sizeof(children));
	}
	~Trie() {
		FOR(i,26) if(children[i]) delete children[i];
	}
	void insert(const char* key) {
		if(*key==0) finish=true;
		else {
			int next=*key-'A';
			if(children[next]==NULL) children[next]=new Trie();
			children[next]->insert(key+1);
		}
	}
	Trie* find(const char* key) {
		if(*key==0) return this;
		int next=*key-'A';
		if(children[next]==NULL) return NULL;
		children[next]->find(key+1);
	}
};


// using string
struct Trie {
    bool terminal;
    Trie* children[26];
    
    Trie(): terminal(false) {
        memset(children,0,sizeof(children));
    }
    ~Trie() {
        FOR(i,26) if(children[i]) delete children[i];
    }
    
    void insert(string& s,int idx) {
        if(idx==s.size()) terminal=true;
        else {
            int next = s[idx]-'A';
            if(children[next]==NULL) children[next] = new Trie();
            children[next]->insert(s,idx+1);
        }
    }
    
    bool find(string& s,int idx) {
        if(idx==s.size()) return false;
        if(terminal) return true;
        int next = s[idx]-'A';
        if(children[next]==NULL) return false;
        return children[next]->find(s,idx+1);
    }
    
};
