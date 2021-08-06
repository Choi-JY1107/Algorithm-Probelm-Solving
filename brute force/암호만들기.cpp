#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int pwLength, alphaCount, ans = 0;
char alpha[17];

void printVector(const vector <char> v){
	for(int i=0;i<pwLength;i++) cout << v.at(i);
	cout << "\n";
}

void findAns(vector <char> v, int index, int con, int vow){
	if(v.size() == pwLength){
		if(con >= 2 && vow >= 1) printVector(v);
		return;
	}
	if(index == alphaCount) return;
	
	v.push_back(alpha[index]);
	if(alpha[index] == 'a' ||
		alpha[index] == 'e' ||
		alpha[index] == 'i' ||
		alpha[index] == 'o' ||
		alpha[index] == 'u') 
		findAns(v,index+1,con,vow+1);
	else 
		findAns(v,index+1,con+1,vow);
	v.pop_back();
	findAns(v,index+1,con,vow);
}

int main(){
	vector <char> v;
	cin >> pwLength >> alphaCount;
	
	for(int i=0;i<alphaCount;i++)
		cin >> alpha[i];
	
	sort(alpha, alpha+alphaCount);
	
	findAns(v,0,0,0);
}
