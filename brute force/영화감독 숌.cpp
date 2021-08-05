#include<stdio.h>
int main(){
	int n,i,temp;
	scanf("%d",&n);
	
	for(i=666;n;i++){
		temp=i;
		while(temp>100){
			if(temp%1000 == 666){
				n--;
				temp/=10;
				break;
			}
			temp/=10;
		}
	}
	printf("%d",i-1);
}
