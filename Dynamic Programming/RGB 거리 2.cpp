#include <stdio.h>
#define MAX 987654321

int n, ans, firstColor;
int costs[1002][3], dp[1002][3];

void findAns(int now){
	
	for(int nowColor=0;nowColor<3;++nowColor){
		int min = MAX;
		for(int preColor=0;preColor<3;++preColor){
			if(nowColor == preColor) continue;
			if(now == n-1 && nowColor == firstColor) continue;
			if(min > dp[now-1][preColor]) min = dp[now-1][preColor];
		}
		dp[now][nowColor] = min + costs[now][nowColor];
		if(now == n-1 && ans > dp[now][nowColor]) ans = dp[now][nowColor]; 
	}
}

int main(void) {
	ans = MAX;
	scanf("%d",&n);
	
	for(int i=0;i<n;++i)
		for(int j=0;j<3;++j)
			scanf("%d",&costs[i][j]);
	
	for(firstColor = 0; firstColor<3; ++firstColor){
		for(int init=0; init<3; ++init) dp[0][init] = (init == firstColor ? costs[0][init] : MAX);
		for(int i=1;i<n;++i) findAns(i);
	}
	
	printf("%d",ans);
}
