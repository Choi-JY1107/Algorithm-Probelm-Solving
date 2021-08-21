#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int cache[101][101];

string W, S;

bool match(int w, int s){
	int& ret = cache[w][s];
	if(ret != -1) return ret;
	
	if(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) 
		return ret = match(w+1, s+1);
	if(w == W.size() && s == S.size())
		return ret = 1;
	if(W[w] == '*')
		if(match(w+1, s) || (s < S.size() && match(w, s+1)))
			return ret = 1;
	return ret = 0;
}

int main() {
	int testcase, n;
	cin >> testcase;
	
	while(testcase--){
		W.clear();
		
		cin >> W;
		cin >> n;
		
		vector <string> patterns(n);
		vector <string> ans;
		
		for(int i=0;i<n;++i)
			cin >> patterns[i];
		
		for(int i=0;i<n;++i){
			memset(cache, -1, sizeof(cache));
			S = patterns[i];
			if(match(0, 0))
				ans.push_back(S);
		}
					
		sort(ans.begin(), ans.end());
		for(int i=0;i<ans.size();++i)
			cout << ans[i] << endl;
	}
	return 0;
}
