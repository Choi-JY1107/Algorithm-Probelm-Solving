#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n;
vector <int> arr, idx, reans;
vector <pair <int, int> > ans;

void lis(int now){
	if(now == n) return;
	
	if(ans.empty() || ans.back().first < arr[now]){
		if(ans.empty()) idx.push_back(-1);
		else idx.push_back(ans.back().second);
		
		ans.push_back(make_pair(arr[now], now));
	}
	else{
		int left = 0;
		int right = ans.size()-1;
		while(left <= right){
			int mid = (left + right) / 2;
			
			if(ans[mid].first < arr[now]) left = mid + 1;
			else right = mid - 1;
		}
		ans[right + 1].first = arr[now];
		ans[right + 1].second = now;
		idx.push_back(right + 1 != 0 ? ans[right].second : -1);
	}
	
	lis(now+1);
}

int main() {
	int temp;
	
	cin >> n;
		
	for(int i=0;i<n;++i){
		cin >> temp;
		arr.push_back(temp);
	}
		
	lis(0);
	
	for(int i = ans.back().second; i != -1; i = idx.at(i))
		reans.push_back(arr.at(i));
	cout << reans.size() << endl;
	for(int i = 0; !reans.empty(); reans.pop_back())
		cout << reans.back() << " ";
	
	return 0;
}
