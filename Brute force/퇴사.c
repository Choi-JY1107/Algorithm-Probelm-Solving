#include<stdio.h>
int day;
int ans = 0;

struct{
	int time;
	int price;
} consult[16];

void dp(int today, int now){
	if(today == day){
		ans = (ans < now ? now : ans);
		return;
	}
	if(today > day) return;
	
	dp(today+1,now);
	dp(today+consult[today].time, now+consult[today].price);
}

int main(){
	scanf("%d",&day);
	
	for(int i=0;i<day;i++)
		scanf("%d %d",&consult[i].time, &consult[i].price);
		
	dp(0,0);
	printf("%d",ans);
} 
