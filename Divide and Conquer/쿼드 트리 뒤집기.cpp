#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it){
	char head = *it;
	++it;
	if(head == 'b' || head == 'w')
		return string(1,head);
		
	string ul,ur,ll,lr;
	ul = reverse(it);
	ur = reverse(it);
	ll = reverse(it);
	lr = reverse(it);
	
	return string("x") + ll + lr + ul + ur;
}

int main() {
	int testcase;
	string str;
	string::iterator it;
	cin >> testcase;
	
	for(int i=0;i<testcase;i++){
		cin >> str;
		it = str.begin();
		cout << reverse(it) << endl;
	}
	return 0;
}
