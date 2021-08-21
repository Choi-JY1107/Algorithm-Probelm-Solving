#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> array, ans;


void lis(int now){
	if(now == n) return;
	
	if(ans.empty() || ans.back() < array[now])
		ans.push_back(array[now]);
	
	int left = 0;
	int right = ans.size()-1;
	while(left <= right){
		int mid = (left + right) / 2;
		
		if(ans[mid] < array[now]) left = mid + 1;
		else right = mid - 1;
	}
	ans[right + 1] = array[now];
	
	lis(now+1);
}

int main() {
	int testcase, temp;
	cin >> testcase;
	
	while(testcase--){
		cin >> n;
		ans.clear();array.clear();
		
		for(int i=0;i<n;++i){
			cin >> temp;
			array.push_back(temp);
		}
		
		lis(0);
		cout << ans.size() << endl;
	}
	return 0;
}
