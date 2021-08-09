#include<stdio.h>
long long c;
long long findAns(long long a, long long b){
    if(b == 1) return a;
    if(b%2) return findAns(a,b-1)*a;
    
    long long temp = findAns(a,b/2) % c;
    return (temp * temp) % c;
}

int main(){
    long long a,b;
    scanf("%lld %lld %lld",&a,&b,&c);
    printf("%lld",findAns(a,b)%c);
}
