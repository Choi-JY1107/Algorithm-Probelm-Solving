#include<stdio.h>
int size, countW, countB;
int array[129][129];

//0 white, 1 blue
int findAns(int x, int y, int len){
	int flag = 1;
	int color[4];
	if(len == 1) return array[x][y];
	
	color[0] = findAns(x, y, len/2);
	color[1] = findAns(x, y + len/2, len/2);
	color[2] = findAns(x + len/2, y, len/2);
	color[3] = findAns(x + len/2, y + len/2, len/2);
	for(int i=1;i<4;++i)
		if(color[0] != color[i])
			flag = 0;
	
	if(flag)
		return color[0];
	else{
		for(int i=0;i<4;i++){
			if(color[i] == 0) countW++;
			else if(color[i] == 1) countB++;
		}
		return -1;
	}
}

int main(){
	countW = countB = 0;
	scanf("%d",&size);
	
	for(int i=0;i<size;++i)
		for(int j=0;j<size;++j)
			scanf("%d",&array[i][j]);
	
	int finish = findAns(0,0,size);
	if(finish == 0) countW++;
	else if(finish == 1) countB++;
	printf("%d\n%d", countW, countB);
}
