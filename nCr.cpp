/*

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef priority_queue<int> MaxHeap;
typedef priority_queue<int, vector<int>, greater<int> > MinHeap;
typedef stack<int> Stack;
typedef queue<int> Queue;
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
const static int N = 1e5 + 10;
ll fact[N], inv_fact[N];

ll power(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b & 1){
			res = (res *1ll* a) % mod;
		}
		a = (a * 1ll * a) % mod;
		b = b >> 1;
	}
	return res;
}

void solve(){
	fact[0] = 1;
	ll i;
	for(i = 1; i < N; i++){
		fact[i] = (fact[i - 1] *1ll* i) % mod;
	}
	i--;
	inv_fact[i] = power(fact[i], mod - 2);
	for(i-- ; i >= 0; i--){
		inv_fact[i] = (inv_fact[i + 1] * 1ll * (i + 1)) % mod;
	}
}

ll nCr(ll n, ll r){
	if(r > n or n < 0 or r < 0){
		return 0;
	}
	return (fact[n] *1ll* inv_fact[r] *1ll* inv_fact[n - r]) % mod;
}

int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	ll n, r;
	cin >> n >> r;
	solve();
	cout << nCr(n, r) << ln;
}
