#include <iostream>
using namespace std;
const int MOD = 10000000;
int cache[101][101];

int poly(int n, int now){
	if(n == now) return 1;
	
	int& ret = cache[n][now];
	if(ret != -1) return ret;
	ret = 0;
	
	for(int next=1; next<=n-now; ++next){
		int add = next + now - 1;
		add *= poly(n-now, next);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int main() {
	int testcase, n;
	for(int i=0; i<101; ++i)
		for(int j=0; j<101; ++j)
			cache[i][j] = -1;
	cin >> testcase;
	
	for(int i=0; i<testcase; ++i){
		int ans = 0;
		cin >> n;
		
		for(int i=1; i<=n; ++i){
			ans += poly(n, i);
			ans %= MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
