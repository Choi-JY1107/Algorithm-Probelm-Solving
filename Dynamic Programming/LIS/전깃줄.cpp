#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> arr, ans;

typedef struct{
	int left;
	int right;
} line;

bool cmp(line a, line b){
	return a.left < b.left;
}

void lis(int now){
	if(now == n) return;
	
	if(ans.empty() || ans.back() < arr[now])
		ans.push_back(arr[now]);
	
	int left = 0;
	int right = ans.size()-1;
	while(left <= right){
		int mid = (left + right) / 2;
		
		if(ans[mid] < arr[now]) left = mid + 1;
		else right = mid - 1;
	}
	ans[right + 1] = arr[now];
	
	lis(now+1);
}

int main() {
	int temp;
	line lines[501];
	
	cin >> n;
		
	for(int i=0;i<n;++i)
		cin >> lines[i].left >> lines[i].right;
	sort(lines, lines+n, cmp);
	for(int i=0;i<n;++i)
		arr.push_back(lines[i].right);
	
	lis(0);
	cout << n-ans.size() << endl;
	
	return 0;
}
