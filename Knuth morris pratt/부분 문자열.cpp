#include <iostream>
#include <string>
#include <vector>
using namespace std;
int pi[1000002] = {0};

void getPi(const string &find){
	int equal = 0; 
	int Size = find.size();
	for(int i=1;i<Size;i++){
		while(equal>0 && find[i] != find[equal]) equal = pi[equal-1];
		
		if(find[i] == find[equal]) pi[i] = ++equal;
	}
}

bool kmp(const string &entry, const string& find){
	int findIndex = 0;
	int entrySize = entry.size();
	int findSize = find.size();
	
	for(int i=0;i<entrySize;++i){
		while(findIndex > 0 && entry[i] != find[findIndex])
			findIndex = pi[findIndex-1];
		
		if(entry[i] == find[findIndex]){
			if(findIndex == findSize-1)
                return true;
			else ++findIndex;
		}
	}
    return false;
}

int main() {
	string entry, find;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	getline(cin, entry);
	getline(cin, find);
	
	getPi(find);
	if(kmp(entry, find)) cout << 1;
    else cout << 0;
    
	return 0;
}
