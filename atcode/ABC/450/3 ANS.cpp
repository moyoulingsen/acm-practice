#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
#define rep(i,l,r)for(int i=(l);i<(r);i++)
#define idx(i,j) ((i)*w+(j))

int main(){
	int h, w;
	cin >> h >> w;
	vector<string>s(h);
	rep(i, 0, h) cin >> s[i];
	
	atcoder::dsu d(h*w);
	rep(i, 0, h)rep(j, 0, w-1)if(s[i][j]=='.' && s[i][j+1]=='.'){
		d.merge(idx(i, j), idx(i, j+1));
	}
	rep(i, 0, h-1)rep(j, 0, w)if(s[i][j]=='.' && s[i+1][j]=='.'){
		d.merge(idx(i, j), idx(i+1, j));
	}
	
	set<int>s1,s2;
	rep(i, 0, h)rep(j, 0, w)if(s[i][j]=='.'){
		s1.insert(d.leader(idx(i, j)));
		if(i==0 || i==h-1 || j==0 || j==w-1){
			s2.insert(d.leader(idx(i, j)));
		}
	}
	
	cout  <<  s1.size() - s2.size() << endl;
}
