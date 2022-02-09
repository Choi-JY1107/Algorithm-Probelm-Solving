#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
const double PI = 3.1415926535;
using namespace std;

struct coor{
	int x;
	int y;
};
vector < coor > coors;
vector < int > convex;

long long ccw(coor a, coor b, coor c) {
	int x1 = a.x;
	int y1 = a.y;
	int x2 = b.x;
	int y2 = b.y;
	int x3 = c.x;
	int y3 = c.y;
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}
bool init(coor a, coor b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool compare(coor a, coor b){
	int temp = ccw(coors[0], a, b);
	if(temp == 0) return a.x - b.x < 0;
	return temp > 0;
}

void findAns(int nowIndex){
	if(nowIndex == coors.size()) return;
	
	while(convex.size() > 1 && ccw(coors[convex[convex.size()-2]], 
								   coors[convex[convex.size()-1]],
								   coors[nowIndex]) <= 0)
		convex.pop_back();
		
	convex.push_back(nowIndex);
	findAns(nowIndex+1);
	
}
int main() {
	int n, l;
	coor temp;
	double ans;
	
	cin >> n >> l;
	for(int i=0;i<n;i++){
		cin >> temp.x >> temp.y;
		coors.push_back(temp);
	}
	
	sort(coors.begin(), coors.end(), init);
	convex.push_back(0);
	sort(coors.begin() + 1, coors.end(), compare);
	convex.push_back(1);
	findAns(2);
	
	for(int i=0; i<convex.size(); i++){
		int x1, y1, x2, y2;
		x1 = coors[convex[i]].x;
		y1 = coors[convex[i]].y;
		
		if(i == 0) {
			x2 = coors[convex[convex.size()-1]].x;
			y2 = coors[convex[convex.size()-1]].y;
		}
		else{
			x2 = coors[convex[i-1]].x;
			y2 = coors[convex[i-1]].y;
		}
		
		ans += sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
	}
	ans += 2 * PI * l;
	cout << round(ans);
	
	return 0;
}
