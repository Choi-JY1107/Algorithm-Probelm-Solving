#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m, ans=64;
bool stand, array[51][51];

int findAns(int x, int y){
	int cnt = 0;
	stand = ((x+y)%2) ^ array[x][y];
	
	for(int i=x;i<x+8;i++)
		for(int j=y;j<y+8;j++)
			if(stand ^ (((i+j)%2) ^ array[i][j]) )
				cnt++;
	if(cnt>=32) cnt = 64-cnt;
	return cnt;
}

int main(){
	char c, stand;
	scanf("%d %d", &n, &m);
	while(getchar() != '\n');
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%c",&c);
			array[i][j] = (c == 'B' ? true : false);
		}
		getchar();
	}
	
	for(int i=0;i<n-7;i++)
		for(int j=0;j<m-7;j++)
			ans = min(findAns(i,j), ans);
	
	
	printf("%d",ans);
}
