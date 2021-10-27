#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n;
vector <int> idx;
bool check[100001];
vector <pair <int, int> > arr, ans;

void lis(int now){
	if(now == n) return;
	
	if(ans.empty() || ans.back().first < arr[now].second){
		if(ans.empty()) idx.push_back(-1);
		else idx.push_back(ans.back().second);
		
		ans.push_back(make_pair(arr[now].second, now));
	}
	else{
		int left = 0;
		int right = ans.size()-1;
		while(left <= right){
			int mid = (left + right) / 2;
			
			if(ans[mid].first < arr[now].second) left = mid + 1;
			else right = mid - 1;
		}
		ans[right + 1].first = arr[now].second;
		ans[right + 1].second = now;
		idx.push_back(right + 1 != 0 ? ans[right].second : -1);
	}
	
	lis(now+1);
}

int main() {
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int temp1, temp2, count=0;
	cin >> n;
		
	for(int i=0;i<n;++i){
		cin >> temp1 >> temp2;
		arr.push_back(make_pair(temp1, temp2));
	}
	
	sort(arr.begin(), arr.end());
	lis(0);
	
	for(int i = ans.back().second; i != -1; i = idx[i]){
		check[i] = true;
		count++;
	}
	cout << n-count << "\n";
	for(int i=0;i<n;++i)
		if(!check[i])
			cout << arr[i].first << "\n";
	
	return 0;
}
