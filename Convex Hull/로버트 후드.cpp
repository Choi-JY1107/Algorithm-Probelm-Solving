#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define PI 3.14159
using namespace std;

struct coor{
	int x;
	int y;
};
struct vertex{
	int index;
	double angle;
};
vector < coor > coors;
vector < vertex > convex;
bool flag;

double findAngle(int now){
	int pre = convex.back().index;
	return atan2(coors.at(now).x - coors.at(pre).x, coors.at(now).y - coors.at(pre).y);
}
bool checkClock(double now){
	double pre = convex.back().angle;
	
	if(pre == 0){
		if(now > 0 && now != PI) return false;
		else return true;
	}
	else if(pre > 0){
		if(pre - PI <= now && pre >= now) return true;
		else return false;
	}
	else{
		if(PI + pre > now && pre < now) return false;
		else return true;
	}
}
bool init(coor a, coor b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool compare(coor a, coor b){
	coor stand = coors.at(0);
	double angle1 = atan2(a.x - stand.x, a.y - stand.y);
	double angle2 = atan2(b.x - stand.x, b.y - stand.y);
	if(angle1 == angle2){
		if(a.x == b.x) return a.y < b.y;
		else return a.x > b.x;
	}
	return angle1 < angle2;
}

void findAns(int nowIndex){
	flag = true;
	if(nowIndex == coors.size()){
		nowIndex = 0;
		flag = false;
	}
	double nowAngle = findAngle(nowIndex);
	
	while(convex.size() > 1 && checkClock(nowAngle)){
		convex.pop_back();
		nowAngle = findAngle(nowIndex);
	}
	if(flag) {
		convex.push_back({nowIndex, nowAngle});
		findAns(nowIndex+1);
	}
}
int main() {
	int n;
	double ans = 0;
	coor temp;
	cin >> n;
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp.x, &temp.y);
		coors.push_back(temp);
	}
	
	sort(coors.begin(), coors.end(), init);
	convex.push_back({0,(double)(-100)});
	sort(coors.begin() + 1, coors.end(), compare);
	findAns(1);
	
	int Size = convex.size();
	for(int i=0;i<Size;++i){
		int x1 = coors[convex[i].index].x;
		int y1 = coors[convex[i].index].y;
		
		for(int j=i+1;j<Size;++j){
			int x2 = coors[convex[j].index].x;
			int y2 = coors[convex[j].index].y;
			ans = max(ans, sqrt((double)(pow((double)(x1-x2),2) + pow((double)(y1-y2),2))));
		}
	}
	cout.precision(15);
	cout << ans;
}
