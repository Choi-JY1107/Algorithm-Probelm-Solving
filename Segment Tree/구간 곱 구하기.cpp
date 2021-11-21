#include <iostream>
#include <cmath>
#include <vector>
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;

int start, end;
ll arr[1000002];
vector <ll> st;

ll makeST(int node, int start, int end)
{
	if (start == end) return st[node] = arr[start];
    
    int mid = (start + end) / 2;
    ll l = makeST(node * 2, start, mid);
    ll r = makeST(node * 2 + 1, mid + 1, end);
    st[node] = (l * r) % MOD;
 
    return st[node];
}

ll mulST(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return st[node];
 
	int mid = (start + end) / 2;
	ll l = mulST(node * 2, start, mid, left, right);
    ll r = mulST(node * 2 + 1, mid + 1, end, left, right);
    return (l * r) % MOD;
}

ll updateST(int node, int start, int end, int index, ll replace)
{
    if (index < start || index > end) return st[node];
    if (start == end) return st[node] = replace;
    else{
        int mid = (start + end) / 2;
        
        st[node] = updateST(node * 2, start, mid, index, replace);
        st[node] %= MOD;
        st[node] *= updateST(node * 2 + 1, mid + 1, end, index, replace);
        st[node] %= MOD;
        return st[node];
    }
 
}
 
int main(void)
{
	int n, m, k, com, a;
	ll b;
	cin >> n >> m >> k;
	int treeH = (int)ceil(log2(n));
	int treeS = (1 << (treeH + 1));
	st.resize(treeS);
	st.assign(treeS, 1);
   
	for(int i=0; i<n; ++i) cin >> arr[i];
	makeST(1, 0, n-1);
   
	for(int i=0; i<m+k; ++i){
		cin >> com >> a >> b;
		
		if(com == 1) {
			updateST(1, 0, n-1, a-1, b);
			arr[a-1] = b;
		}
		else cout << mulST(1, 0, n-1, a-1, b-1) << endl;
	}
}
