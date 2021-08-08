#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
int h[20003];

int solve(int left, int right){
	if(left == right) return h[left];
	
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid+1, right));
	int lo = mid, hi = mid+1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height*2);
	
	while(left < lo || hi < right) {
		if(hi < right && (left == lo || h[lo-1] < h[hi+1])){
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height*(hi - lo + 1));
	}
	return ret;
}

int main() {
	int testcase;
	cin >> testcase;
	
	for(int i=0;i<testcase;i++){
		cin >> n;
		memset(h, 0, sizeof(int) * (n+1));
		for(int j=0;j<n;j++)
			cin >> h[j];
		cout << solve(0,n) << endl;
	}
	return 0;
}
