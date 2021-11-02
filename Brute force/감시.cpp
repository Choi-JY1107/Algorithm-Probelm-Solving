#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void variety(int now);

int n, m, ans = 64;
int office[9][9], vision[9][9];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector <pair <int, int> > cctv;

void print(){
	for(int i=0; i<n; ++i, cout << endl)
			for(int j=0; j<m; ++j)
				cout << vision[i][j] << " ";
	cout << endl;
}
void findAns(){
	int temp=0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(vision[i][j] == 0)
				temp++;
	
	//if(temp < ans) print();
	ans = min(temp, ans);
}

void copyVision(int tempArr[9][9]){
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			tempArr[i][j] = vision[i][j];
}
void copyTemp(int tempArr[9][9]){
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			vision[i][j] = tempArr[i][j];
}

void fir(int now){
	int temp[9][9];
	copyVision(temp);
	
	for(int i=0; i<4; ++i){
		copyTemp(temp);
		
		int dy = cctv[now].first + dir[i][0];
		int dx = cctv[now].second + dir[i][1];
		while(dy >= 0 && dy < n && dx >= 0 && dx < m && 
		vision[dy][dx] != 6){
			vision[dy][dx] = -1;
			dy += dir[i][0];
			dx += dir[i][1];
		}
		if(now == cctv.size()-1) findAns();
		else variety(now + 1);
	}
}
void sec(int now){
	int temp[9][9];
	copyVision(temp);
	
	for(int i=0; i<2; ++i){
		copyTemp(temp);
		
		int dy = cctv[now].first + dir[i][0];
		int dx = cctv[now].second + dir[i][1];
		while(dy >= 0 && dy < n && dx >= 0 && dx < m && 
		vision[dy][dx] != 6){
			vision[dy][dx] = -1;
			dy += dir[i][0];
			dx += dir[i][1];
		}
		
		dy = cctv[now].first + dir[i+2][0];
		dx = cctv[now].second + dir[i+2][1];
		while(dy >= 0 && dy < n && dx >= 0 && dx < m && 
		vision[dy][dx] != 6){
			vision[dy][dx] = -1;
			dy += dir[i+2][0];
			dx += dir[i+2][1];
		}
		
		if(now == cctv.size()-1) findAns();
		else variety(now + 1);
	}
}
void thi(int now){
	int temp[9][9];
	copyVision(temp);
	
	for(int i=0; i<4; ++i){
		copyTemp(temp);
		
		int dy = cctv[now].first + dir[i][0];
		int dx = cctv[now].second + dir[i][1];
		while(dy >= 0 && dy < n && dx >= 0 && dx < m && 
		vision[dy][dx] != 6){
			vision[dy][dx] = -1;
			dy += dir[i][0];
			dx += dir[i][1];
		}
		
		dy = cctv[now].first + dir[(i+1)%4][0];
		dx = cctv[now].second + dir[(i+1)%4][1];
		while(dy >= 0 && dy < n && dx >= 0 && dx < m && 
		vision[dy][dx] != 6){
			vision[dy][dx] = -1;
			dy += dir[(i+1)%4][0];
			dx += dir[(i+1)%4][1];
		}
		
		if(now == cctv.size()-1) findAns();
		else variety(now + 1);
	}
}
void four(int now){
	int temp[9][9];
	copyVision(temp);
	
	for(int i=0; i<4; ++i){
		copyTemp(temp);
		
		int dy = cctv[now].first + dir[i][0];
		int dx = cctv[now].second + dir[i][1];
		while(dy >= 0 && dy < n && dx >= 0 && dx < m && 
		vision[dy][dx] != 6){
			vision[dy][dx] = -1;
			dy += dir[i][0];
			dx += dir[i][1];
		}
		
		dy = cctv[now].first + dir[(i+1)%4][0];
		dx = cctv[now].second + dir[(i+1)%4][1];
		while(dy >= 0 && dy < n && dx >= 0 && dx < m && 
		vision[dy][dx] != 6){
			vision[dy][dx] = -1;
			dy += dir[(i+1)%4][0];
			dx += dir[(i+1)%4][1];
		}
		
		dy = cctv[now].first + dir[(i+2)%4][0];
		dx = cctv[now].second + dir[(i+2)%4][1];
		while(dy >= 0 && dy < n && dx >= 0 && dx < m && 
		vision[dy][dx] != 6){
			vision[dy][dx] = -1;
			dy += dir[(i+2)%4][0];
			dx += dir[(i+2)%4][1];
		}
		
		if(now == cctv.size()-1) findAns();
		else variety(now + 1);
	}
}
void fif(int now){
	int temp[9][9];
	copyVision(temp);
	
	for(int i=0; i<4; ++i){
		int dy = cctv[now].first + dir[i][0];
		int dx = cctv[now].second + dir[i][1];
		while(dy >= 0 && dy < n && dx >= 0 && dx < m && 
		vision[dy][dx] != 6){
			vision[dy][dx] = -1;
			dy += dir[i][0];
			dx += dir[i][1];
		}
	}
	if(now == cctv.size()-1) findAns();
	else variety(now + 1);
	
	copyTemp(temp);
}

void variety(int now){
	if(office[cctv[now].first][cctv[now].second] == 1) fir(now);
	else if(office[cctv[now].first][cctv[now].second] == 2) sec(now);
	else if(office[cctv[now].first][cctv[now].second] == 3) thi(now);
	else if(office[cctv[now].first][cctv[now].second] == 4) four(now);
	else if(office[cctv[now].first][cctv[now].second] == 5) fif(now);
}

int main() {
	cin >> n >> m;
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin >> office[i][j];
			if(office[i][j] && office[i][j] != 6)
				cctv.push_back(make_pair(i, j));
		}
	}
	
	copyTemp(office);
	if(!cctv.empty()) variety(0);
	findAns();
	
	cout << ans << endl;
	return 0;
}
