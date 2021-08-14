#include <iostream>
#include <vector>
#define divisor 1000000007
using namespace std;
typedef vector < vector <long long> > vv;

vv unit = { {1, 1}, {1, 0} };

void print(vv a){
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j)
			cout << a[i][j] << " " ;
		cout << endl;
	}
	cout << endl;
}

vv multiply(vv a, vv b){
	vv c(2, vector <long long>(2));
	
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
					c[i][j] += (a[i][k] * b[k][j]) % divisor; 
	
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			c[i][j] %= divisor;
			
	return c;
}

vv findAns(long long n){
	if(n == 1) return unit;
	
	if(n%2){
		vv temp = findAns(n-1);
		return multiply(unit, temp);
	}
	else{
		vv temp = findAns(n/2);
		return multiply(temp, temp);
	}
}

int main() {
	vv last;
	long long n;
	cin >> n;
	
	if(n <= 2) printf("1");
	else {
		last = findAns(n-2);
		cout << (last[0][0] + last[0][1]) % divisor << endl;
	}
	
	return 0;
}
