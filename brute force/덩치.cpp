#include <iostream>
using namespace std;

struct{
	int weight;
	int height;
	int rank = 1;
} person[51];

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++)
		cin >> person[i].weight >> person[i].height;
		
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j) continue;
			if(person[i].weight < person[j].weight && 
			person[i].height < person[j].height) person[i].rank++;
		}
	}
	
	for(int i=0;i<n;i++)
		cout << person[i].rank << " ";
	cout << endl;
}
