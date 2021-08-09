#include <iostream>
#include <vector>
using namespace std;

int mSize;
typedef vector < vector <int> > Vector;
Vector array;

Vector multiply(Vector a, Vector b){
	Vector arr;
	for(int i=0;i<mSize;++i){
		vector <int> vectorTemp;
		for(int j=0;j<mSize;++j){
			int intTemp = 0;
			for(int k=0;k<mSize;++k){
				intTemp += a[i][k] * b[k][j];
				intTemp %= 1000;
			}
			vectorTemp.push_back(intTemp);
		}
		arr.push_back(vectorTemp);
	}
	return arr;
}

Vector findAns(long long count){
	Vector temp;
	
	if(count == 1) temp.assign(array.begin(), array.end());
	else if(count%2){
		temp = findAns(count-1);
		temp = multiply(temp,array);
	}
	else {
		temp = findAns(count/2);
		temp = multiply(temp,temp);
	}
	return temp;
}

int main(void) {
	Vector ans;
	long long count;
	cin >> mSize;
	cin >> count;
	
	for(int i=0;i<mSize;++i){
		vector <int> vectorTemp;
		int intTemp;
		for(int j=0;j<mSize;++j){
			cin >> intTemp;
			vectorTemp.push_back(intTemp);
		}
		array.push_back(vectorTemp);
	}
	
	ans = findAns(count);
	
	for(int i=0;i<mSize;++i){
		for(int j=0;j<mSize;++j)
			cout << ans[i][j]%1000 << " ";
		cout << "\n";
	}
	return 0;
}
