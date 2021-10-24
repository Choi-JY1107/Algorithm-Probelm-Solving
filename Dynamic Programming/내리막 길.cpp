#include<iostream>
#include<cstring>
using namespace std;

int n, m;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int board[501][501], cache[501][501];

int dp(int x, int y){
    if(x == n-1 && y == m-1) return 1;
    
    int& ret = cache[x][y];
    if(ret != -1) return ret;
    ret = 0;
    
    for(int i=0; i<4; ++i){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx < 0 || dy < 0 || dx == n || dy == m ||
          board[x][y] <= board[dx][dy]) continue;
          
        //cout << "dx is " << dx << ", and dy is " << dy << endl;
        ret += dp(dx, dy);
    }
    return ret;
}

int main(){
    cin >> n >> m;
    memset(cache, -1, sizeof(cache));
    
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> board[i][j];
    
    cout << dp(0,0) << endl;
}
