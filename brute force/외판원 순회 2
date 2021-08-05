#include <iostream>
#include <stack>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, start, nextCost, ans = INF;
int cost[17][17];
bool visit[17];
stack <int> s;

void findAns(int now){
	if(s.size() == n){
		if(!cost[s.top()][start]) return;
		ans = min(ans, now + cost[s.top()][start]);
		return;
	}
		
	for(int i=0;i<n;i++){
		if(visit[i] || (s.size() && !cost[s.top()][i])) continue;
		
		if(s.size()) nextCost = cost[s.top()][i];
		else start = i;

		visit[i] = true;
		s.push(i);
		
		if(start == i) findAns(now);
		else findAns(now + nextCost);
		
		visit[i] = false;
		s.pop();
	}
	return;
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> cost[i][j];
	
	findAns(0);
	
	cout << ans << endl;
}
