#include <iostream>
using namespace std;
int student, friends, ans;
bool connect[10];
bool array[10][10];

void init(){
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			array[i][j] = false;
	for(int i=0;i<10;i++)
		connect[i]=false;
	ans = 0;
}

void findAns(){
	int now, flag = 1;
	for(int i=0;i<student;i++){
		if(!connect[i]){
			flag = 0;
			now = i;
			break;
		}
	}
	if(flag){
		ans++;
		return;
	}
	for(int i=now+1;i<student;i++){
		if(!connect[i]&array[now][i]){
			connect[now] = connect[i] = true;
			findAns();
			connect[now] = connect[i] = false;
		}
	}
	return;
}

int main() {
	int testcase, a, b;
	cin >> testcase;
	
	while(testcase--){
		init();
		cin >> student >> friends;
		for(int i=0;i<friends;i++){
			cin >> a >> b;
			array[a][b] = true;
			array[b][a] = true;
		}
		findAns();
		cout << ans << endl;
	}
	
}
