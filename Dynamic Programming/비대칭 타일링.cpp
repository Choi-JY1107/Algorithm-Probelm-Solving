#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int n;
long long cache[101], cache2[101];

long long tiling(int now){
	long long& ret = cache[now];
	if(ret != -1) return ret;
	
	if(now == 1) ret = 1;
	else if(now == 2) ret = 2;
	else ret = tiling(now-2) + tiling(now-1);
	return ret;
}

long long asymmetric(int now){
	if(now <= 2) return 0;
	long long& ret = cache2[now];
	if(ret != -1) return ret;
	
	ret = asymmetric(now-2) % MOD;
	ret = (ret + asymmetric(now-4)) % MOD;
	ret = (ret + 2 * tiling(now-3)) % MOD;
	return ret;
}


int main() {
	int testcase;
	cin >> testcase;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	
	while(testcase--){
		cin >> n;
		cout << asymmetric(n) << endl;
	}
}
