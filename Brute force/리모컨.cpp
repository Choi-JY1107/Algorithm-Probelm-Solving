#include <iostream>
#include <algorithm>
using namespace std;
int ans, c, num, target, brokenCount;
bool flag;
bool broken[10] = {false};

int checkAns(int n){
	num = 0;
	flag = true;
	do{
		if(broken[n%10]){
			flag = false;
			break;
		}
		n/=10;
		num++;
	} while(n);
	if(flag) return num;
	else return 0;
}

void findAns(int now, int type){
	if(ans < abs(target-now)) return;
	if(now == 100){ 
		ans = min(ans, abs(target-now));
		return;
	}
	
	int cnt = checkAns(now);
	if(cnt){
		ans = min(ans, abs(target-now)+cnt);
		return;
	}
	
	if(now+type == -1) return;
	findAns(now+type,type);
}

int main() {
	cin >> target;
	cin >> brokenCount;
	ans = abs(target-100);
	
	for(int i=0;i<brokenCount;i++){
		cin >> c;
		broken[c] = true;
	}
	
	findAns(target,-1);
	findAns(target,1);
	cout << ans;
}
