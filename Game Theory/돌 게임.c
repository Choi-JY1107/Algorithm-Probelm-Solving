#include <stdio.h>
#include <string.h>
int win[1002];		//1 : n번째인 사람이 이기는 것

int dp(int n){
	if(win[n] != -1) return win[n];
	
	if(dp(n-3) && dp(n-1)) win[n] = 0;
	else win[n] = 1;
	return win[n];
}

int main() {
	int n;
	scanf("%d", &n);
	memset(win, -1, sizeof(int) * 1002);
	
	win[1] = 1;
	win[2] = 0;
	win[3] = 1;
	
	if(dp(n)) printf("SK");
	else printf("CY");
	return 0;
}
