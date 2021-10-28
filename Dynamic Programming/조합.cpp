#include <iostream>
#define divisor 1000000007
typedef long long ll;
using namespace std;

int n, r;
ll target, fac[1000002]={0};

ll power(ll di){
	if(di == 1) return target;
	
	ll temp;
	if(di%2) return (power(di-1) * target) % divisor;
	else{
		temp = power(di/2);
		return (temp * temp) % divisor;
	}
}

int main() {
	fac[1] = 1;
	for(int i=2;i<=1000000;++i)
		fac[i] = fac[i-1] * i % divisor;
		
	cin >> n >> r;
	if(r>n/2) r = n-r;
	if(n == r || r == 0){
		cout << "1";
		return 0;
	}
	cout << n << ", "  << r << endl;
	target = fac[r] * fac[n-r] % divisor;
	cout << fac[n] * power(divisor-2) % divisor;
	
	return 0;
}
