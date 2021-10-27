#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[101][101], countCache[101][101], pathCache[101][101];

int path(int y, int x){
	if(y == n-1) return arr[y][x];
	int& ret = pathCache[y][x];
	if(ret != -1) return ret;
	
	ret = arr[y][x];
	ret += max(path(y+1, x+1), path(y+1, x));
	return ret;
}

int count(int y, int x){
	if(y == n-1) return 1;
	
	int& ret = countCache[y][x];
	if(ret != -1) return ret;
	ret = 0;
	
	if(path(y+1, x+1) >= path(y+1,x)) ret += count(y+1, x+1);
	if(path(y+1, x+1) <= path(y+1,x)) ret += count(y+1, x);
	return ret;
}

int main() {
	int testcase;
	cin >> testcase;
	
	for(int i=0;i<testcase;++i){
		cin >> n;
		
		for(int j=0;j<n;++j)
			memset(countCache[j], -1, sizeof(int)*(j+1));
		for(int j=0;j<n;++j)
			memset(pathCache[j], -1, sizeof(int)*(j+1));
		
		for(int j=0;j<n;++j)
			for(int k=0;k<=j;++k)
				cin >> arr[j][k];
		
		cout << count(0,0) << endl;
	}
}
