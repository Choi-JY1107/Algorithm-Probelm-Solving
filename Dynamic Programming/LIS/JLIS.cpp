#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m;
int cache[101][101];
vector <int> A, B, ans;

int jlis(int nowA, int nowB){
	int& ret = cache[nowA+1][nowB+1];
	if(ret != -1) return ret;
	
	ret = 2;
	long long a = (nowA == -1 ? NEGINF : A[nowA]);
	long long b = (nowB == -1 ? NEGINF : B[nowB]);
	long long maxElement = max(a,b);
	
	for(int nextA = nowA + 1 ; nextA < n; ++nextA)
		if(maxElement < A[nextA])
			ret = max(ret, jlis(nextA, nowB) + 1);
			
	for(int nextB = nowB + 1 ; nextB < m; ++nextB)
		if(maxElement < B[nextB])
			ret = max(ret, jlis(nowA, nextB) + 1);
	
	return ret;
}

int main() {
	int testcase, temp;
	cin >> testcase;
	
	while(testcase--){
		cin >> n >> m;
		A.clear();B.clear();
		for(int i=0;i<101;++i)
			for(int j=0;j<101;++j)
				cache[i][j] = -1;
		
		for(int i=0;i<n;++i){
			cin >> temp;
			A.push_back(temp);
		}
		for(int i=0;i<m;++i){
			cin >> temp;
			B.push_back(temp);
		}
		
		ans.push_back(jlis(-1, -1));
	}
	for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
		cout << *iter << endl;
	return 0;
}
