#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1002
#define MINF -987654321
using namespace std;
int n, m;
int direction[3][2] = { {0, 1}, {0, -1}, {1, 0}};
int arr[MAX][MAX], cache[MAX][MAX][3];
bool check[MAX][MAX];

int explore(int y, int x, int dir){
	if(y == n-1 && x == m-1) return arr[y][x];
	
	int& ret = cache[y][x][dir];
	if(ret != MINF) return ret;
	ret = arr[y][x]; check[y][x] = true;
	
	int temp = MINF;
	for(int i=0; i<3; ++i){
		int dy = y + direction[i][0];
		int dx = x + direction[i][1];
		if(dy < 0 || dx < 0 || dy == n || dx == m || 
		check[dy][dx])
			continue;
		temp = max(temp, explore(dy, dx, i));
	}
	
	ret += temp;
	check[y][x] = false;
	return ret;
}

int main() {
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			for(int k=0; k<3; k++)
				cache[i][j][k] = MINF;
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin >> arr[i][j];
	
	cout << explore(0, 0, 0);
	return 0;
}
