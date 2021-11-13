#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

long long cal(int k){
	if(k == -1) return 0;
	if(k == 0) return 1;
	if(k == 1) return 2;
	
	if(k%2) return (cal(k-1) * 2) % MOD;
	long long temp = cal(k/2) % MOD;
	return (temp * temp) % MOD;
}

int main() {
	int testcase, c, k;
	long long ans = 0;
	cin >> testcase;
	
	for(int i=0; i<testcase; ++i){
		cin >> c >> k;
		long long temp = (cal(k-1) * k) % MOD;
		temp = (temp * c) % MOD;
		ans += temp;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
