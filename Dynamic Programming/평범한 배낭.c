#include<stdio.h>
int var, knapsack;
int ans[100010]={0};
struct item{
	int weight;
	int value;
} items[102];

int max(int a, int b){
	if(a>b) return a;
	return b;
}

void findAns(){
	for(int i=0;i<var;++i)
		for(int j=knapsack;j>=1;--j)
			if(items[i].weight <= j)
				ans[j] = max(ans[j], ans[j-items[i].weight] + items[i].value);
}

int main(){
	scanf("%d %d", &var, &knapsack);
	
	for(int i=0;i<var;++i)
		scanf("%d %d", &items[i].weight, &items[i].value);
	findAns();
	
	printf("%d",ans[knapsack]);
}
