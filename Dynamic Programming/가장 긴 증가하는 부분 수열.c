#include <stdio.h>
int array[1010];
int dp[1010];
int max(int a, int b){
	return a>b ? a : b;
}

int main(void) {
	int size, ans = 0;
	scanf("%d",&size);
	
	for(int i=0;i<size;++i) scanf("%d",&array[i]);
	for(int i=0;i<size;++i) dp[i]=1;
		
	for(int i=0;i<size;++i)
		for(int j=0;j<i;++j)
			if(array[i] > array[j])
				dp[i] = max(dp[i], dp[j]+1);
	
	for(int i=0;i<size;i++) ans = max(ans, dp[i]);
	
	printf("%d", ans);
}
