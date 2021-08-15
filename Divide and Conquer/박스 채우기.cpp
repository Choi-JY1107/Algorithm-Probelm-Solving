#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct cube{
	int size;
	int count;
} cubes[21];
int length, width, height, kinds, cnt = 0;
bool flag = false;

bool cmp(cube a, cube b){
	return a.size > b.size;
}

void findAns(int l, int w, int h){
	if(flag) return;
	if(l ==0 || w == 0 || h == 0) return;
	
	for(int i=0; i<kinds; ++i){
		int nowSize = cubes[i].size;
		int nowCount = cubes[i].count;
		if(nowCount && nowSize <= l && nowSize <= w && nowSize <= h){
			cubes[i].count--;
			cnt++;
			findAns(l-nowSize, w, h);
			findAns(nowSize, nowSize, h-nowSize);
			findAns(nowSize, w-nowSize, h);
			return;
		}
	}
	flag = true;
}

int main() {
	cin >> length >> width >> height;
	cin >> kinds;
	
	for(int i=0;i<kinds;++i){
		int temp1, temp2;
		cin >> temp1 >> temp2;
		cubes[i].size = pow(2,temp1);
		cubes[i].count = temp2;
	}
	sort(cubes, cubes + kinds, cmp);
	findAns(length, width, height);
	cout << (flag ? -1 : cnt) << endl;
}
