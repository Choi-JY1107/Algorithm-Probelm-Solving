#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int cache[101], cache2[101];

int tiling(int n){
	if(n <= 1) return 1;
	
	int& ret = cache[n];
	if(ret != -1) return ret;
	return ret = (tiling(n-2) + tiling(n-1)) % MOD;
}

int asymmetric(int n){
	if(n <= 2) return 0;
	
	int& ret = cache2[n];
	if(ret != -1) return ret;
	ret = asymmetric(n-2) % MOD;
	ret = (ret + asymmetric(n-4)) % MOD;
	ret = (ret + tiling(n-3)) % MOD;
	ret = (ret + tiling(n-3)) % MOD;
	return ret;
	
}

int main() {
	int testcase, n;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> testcase;
	
	for(int i=0; i<testcase; ++i){
		cin >> n;
		cout << asymmetric(n) << endl;
	}
	return 0;
}
