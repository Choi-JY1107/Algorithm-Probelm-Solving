#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 502
using namespace std;
int n;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int arr[MAX][MAX], cache[MAX][MAX];
bool check[MAX][MAX];

int panda(int y, int x){
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	ret = 1; check[y][x] = true;
	
	int temp = 0;
	for(int i=0; i<4; ++i){
		int dy = y + dir[i][0];
		int dx = x + dir[i][1];
		if(dy < 0 || dx < 0 || dy == n || dx == n || 
		check[dy][dx] || arr[y][x] >= arr[dy][dx])
			continue;
		temp = max(temp, panda(dy, dx));
	}
	
	ret += temp;
	check[y][x] = false;
	return ret;
}

int main() {
	int ans = -1;
	cin >> n;
	for(int i=0; i<n; ++i)
		memset(cache[i], -1, sizeof(int) * MAX);
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> arr[i][j];
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			ans = max(ans, panda(i,j));
			
	cout << ans;
	return 0;
}
