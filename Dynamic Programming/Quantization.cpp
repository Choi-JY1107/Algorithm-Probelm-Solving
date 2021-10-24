#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n, cache[101][11];
vector<int> seq;
int pSum[101], pSqSum[101];

void precalc(){
	memset(cache, -1, sizeof(cache));
	memset(pSum, 0, sizeof(pSum));
	memset(pSqSum, 0, sizeof(pSqSum));
	
	sort(seq.begin(), seq.end());
	pSum[0] = seq[0];
	pSqSum[0] = seq[0] * seq[0];
	for(int j=1; j<n; ++j){
		pSum[j] = pSum[j-1] + seq[j];
		pSqSum[j] = pSqSum[j-1] + seq[j] * seq[j];
	}
}

int minError(int lo, int hi){
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
	int m = int(0.5 + (double)sum / (hi-lo+1));
	int ret = sqSum - 2*m*sum + m*m*(hi-lo+1);
	return ret;
}

int quantize(int from, int parts){
	if(from == n) return 0;
	if(parts == 0) return INF;
	int& ret = cache[from][parts];
	if(ret != -1) return ret;
	ret = INF;
	
	for(int partSize = 1; from + partSize <= n; ++partSize)
		ret = min(ret, minError(from, from + partSize - 1) +
						quantize(from + partSize, parts - 1));
	
	return ret;
}

int main(){
	int testcase, temp, s;
	int ans[51];
	cin >> testcase;
	
	for(int i=0; i<testcase; ++i){
		seq.clear();
		cin >> n >> s;
		
		for(int j=0; j<n; ++j){
			cin >> temp;
			seq.push_back(temp);
		}
		precalc();
		ans[i] = quantize(0, s);
	}
	for(int i=0; i<testcase; ++i)
		cout << ans[i] << endl;
}
