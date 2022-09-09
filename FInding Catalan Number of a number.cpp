/* Find the catalan number of a digit

*/

#include<bits/stdc++.h>
using namespace std;

int isSolve(int n){
	int dp[n + 1];
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		dp[i] = 0;
		for(int j = 0; j < i; j++){
			dp[i] += dp[j] *dp[i - j - 1];
		}
	}
	cout << dp[n] << endl;
}

int main(){
	int n;
	cin >> n;
	isSolve(n);
}
