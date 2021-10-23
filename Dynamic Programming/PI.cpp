#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int cache[10002];
string str;

int classify(int start, int end){
	string temp = str.substr(start, end-start+1);
	if(temp == string(temp.size(), temp[0])) return 1;
	
	bool progressive = true;
	for(int i=0; i<temp.size()-1; ++i)
		if(temp[i+1] - temp[i] != temp[1] - temp[0])
			progressive = false;
	if(progressive && abs(temp[1] - temp[0]) == 1)
		return 2;
	
	bool alternating = true;
	for(int i=0; i<temp.size(); ++i)
		if(temp[i] != temp[i%2])
			alternating = false;
	if(alternating) return 4;
	if(progressive) return 5;
	return 10;
}

int memo(int begin){
	if(begin == str.size()) return 0;
	int& ret = cache[begin];
	if(ret != -1) return ret;
	
	ret = INF;
	for(int l=3; l<=5; ++l)
		if(begin + l <= str.size())
			ret = min(ret, memo(begin + l) + 
			classify(begin, begin + l - 1));
	
	return ret;
}

int main(){
	int testcase;
	int ans[51];
	cin >> testcase;
	
	for(int i=0; i<testcase; ++i){
		str.clear();
		cin >> str;
		memset(cache, -1, sizeof(cache));
		ans[i] = memo(0);
	}
	for(int i=0; i<testcase; ++i)
		cout << ans[i] << endl;
}
