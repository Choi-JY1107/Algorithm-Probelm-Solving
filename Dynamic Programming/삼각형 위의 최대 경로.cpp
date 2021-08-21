#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int lines;
int memo[101][101];
vector <vector <int> > tri;

int dp(int x, int y){
	if(memo[x][y] != -1) return memo[x][y];
	
	int a, b;
	a = b = 0;
	if(x-1 >= 0 && y-1 >= 0) a = dp(x-1, y-1);
	if(x-1 >= 0 && x-1 >= y) b = dp(x-1, y);
	return memo[x][y] = max(a, b) + tri[x][y];
}

int main(){
	int testcase, ans, tempInt;
	vector <int> tempVec;
	cin >> testcase;
	
	while(testcase--){
		tri.clear();ans=0;
		memset(memo, -1, sizeof(memo));
		cin >> lines;
		
		for(int i=1;i<=lines;++i){
			tempVec.clear();
			for(int j=0;j<i;++j){
				cin >> tempInt;
				tempVec.push_back(tempInt);
			}
			tri.push_back(tempVec);
		}
		memo[0][0] = tri[0][0];
		
		for(int i=0;i<lines;++i)
			ans = max(ans, dp(lines-1, i));
		cout << ans << endl;
	}
}
