#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, temp, len, tempLen, tempIndex;
vector <int> arr, ans, dp(1000);

void lis(int now){
	len=0;
	
	for(int i=0;i<now;++i)
		if(arr[i] < arr[now])
			len = max(dp[i], len);
	dp[now] = len + 1;
	
	if(tempLen < dp[now]){
		tempLen = dp[now];
		tempIndex = now;
	}
	
	if(now != n) lis(now+1);
}

int main(){
	tempLen = tempIndex = 0;
	cin >> n;
	
	for(int i=0;i<n;++i){
		cin >> temp;
		arr.push_back(temp);
	}
	
	lis(0);
	
	for(int i=tempIndex;tempLen;--i){
		if(dp[i] == tempLen){
			ans.push_back(arr[i]);
			tempLen--;
		}
	}
	
	cout << ans.size() << endl;
	while(!ans.empty()){
		cout << ans.back() << " ";
		ans.pop_back();
	}
	
}
