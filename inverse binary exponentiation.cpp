/*    Inverse Binary Exponentiation

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<int> vi;
typedef priority_queue<int> MaxHeap;
typedef priority_queue<int, vector<int>, greater<int> > MinHeap;
typedef stack<int> Stack;
typedef queue<int> Queue;
typedef pair<int, int> pi;
typedef set<int> oset;
typedef unordered_set<int> uset;
typedef map<int, int> omap;
typedef unordered_map<int, int> umap;
typedef multiset<int> mset;
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ln "\n"

const static int mod = 1e9 + 7;

// a ^ b(we have to count a to the power b)
ll power(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b & 1){
			res = (res * a) % mod;
		}
		a = (a *1LL* a) % mod;
		b = b >> 1;
	}
	return res;
}

int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	a = a % mod;
	ll res = power(b, mod - 2);
	cout << (a * res) % mod << ln;
}
