#include <stdio.h>
#include <string.h>
int n;
int array[101][101];
int visited[101][101];

int jump(int y, int x){
	if(y >= n || x >= n) return 0;
	if(y == n-1 && x == n-1) return 1;
	
	int &ret = visited[y][x];
	if(ret != -1) return ret;
	int jumpSize = array[y][x];
	return ret = jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

int main() {
	int testcase;
	scanf("%d",&testcase);
	
	for(int i=0; i<testcase; ++i){
		memset(visited, -1, sizeof(visited));
		scanf("%d",&n);
		
		for(int j=0;j<n;++j)
			for(int k=0;k<n;++k)
				scanf("%d", &array[j][k]);
		if(jump(0,0) == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
