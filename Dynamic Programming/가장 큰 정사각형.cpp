#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 1002
using namespace std;

int n, m;
int arr[MAX][MAX], cache[MAX][MAX];

int biggest(int y, int x){
	if(arr[y][x] == 0) return 0;
	
	int wid, hei;
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	wid = hei = 1;
	
	bool flag = false;
	if(y != n-1) hei += biggest(y+1, x);
	if(x != m-1) wid += biggest(y, x+1);
	
	for(int i=y; i<y+hei; ++i)
		if(arr[i][x+wid-1] == 0) flag = true;
	if(flag) hei--;
	flag = false;
	
	for(int i=x; i<x+wid; ++i)
		if(arr[y+hei-1][i] == 0) flag = true;
	if(flag) wid--;
	
	ret = min(wid, hei);
	return ret;
}

int main(){
	string temp;
	int ans = -1;
	cin >> n >> m;
	
	for(int i=0; i<MAX; ++i)
		memset(cache[i], -1, sizeof(int) * MAX);
	
	for(int i=0; i<n; ++i){
		cin >> temp;
		for(int j=0; j<m; ++j)
			arr[i][j] = temp[j] - '0';
	}
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			ans = max(ans, biggest(i,j));
	
	cout << ans * ans;
	return 0;
}
