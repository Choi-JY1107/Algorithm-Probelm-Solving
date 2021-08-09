#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int ans, clockArray[17];

vector <vector <int> > pushed = { {0, 1, 2},
								{3, 7, 9, 11},
								{4, 10, 14, 15},
								{0, 4, 5, 6, 7},
								{6, 7, 8, 10, 12},
								{0, 2, 14, 15},
								{3, 14, 15},
								{4, 5, 7, 14, 15},
								{1, 2, 3, 4, 5},
								{3, 4, 5, 9, 13}};

bool checkClock(){
	bool flag = true;
	for(int i=0;i<16;i++)
		if(clockArray[i] != 12)
			flag = false;
	return flag;
}

void changeClock(int swit){
	for(int i=0;i<pushed.at(swit).size();i++)
		clockArray[pushed.at(swit).at(i)]
		= clockArray[pushed.at(swit).at(i)] % 12 + 3;
}

void findAns(int swit, int now){
	if(checkClock()) {
		ans = min(ans, now);
		return;
	}
	if(swit == 10) return;
	
	for(int i=0;i<4;i++){
		findAns(swit + 1, now+i);
		changeClock(swit);
	}
}

int main() {
	int testcase;
	cin >> testcase;
	
	for(int i=0;i<testcase;i++){
		ans = INF;
		for(int j=0;j<16;j++)
			cin >> clockArray[j];
		findAns(0,0);
		cout << (ans == INF ? -1 : ans) << endl;
	}
}
