#include <iostream>
#define MAX 34
using namespace std;

int n, arr[MAX][MAX];
long long cache[MAX][MAX][4];

//dir 1은 가로, 2는 세로, 3은 대각선
long long dp(int y, int x, int dir){
	long long& ret = cache[y][x][dir];
	if(ret != -1) return ret;
	ret = 0;
	
	if(y+1 < n && x+1 < n && arr[y+1][x+1] != 1 && arr[y+1][x] != 1 && arr[y][x+1] != 1)
		ret += dp(y+1, x+1, 3);
	if(dir/2 && y+1 < n && arr[y+1][x] != 1) ret += dp(y+1, x, 2);
	if(dir%2 && x+1 < n && arr[y][x+1] != 1) ret += dp(y, x+1, 1);
	return ret;
}

int main() {
	cin >> n;
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> arr[i][j];
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(int k=1; k<4; ++k)
				cache[i][j][k] = -1;
		
	cache[n-1][n-1][1] = cache[n-1][n-1][2] = cache[n-1][n-1][3] = 1;
	cout << dp(0, 1, 1);
	
	return 0;
}
