/*    Sieve of Eratosthanus

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

const static int N = 1e8;

int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	vi v(N, 0);
	v[1] = 0;
	for(int i = 2; i < N; i++){
		if(v[i]) continue;
		cout << i << " ";
		for(int j = i * i; j < N; j += i){
			v[j]++;
		}
	}
}
