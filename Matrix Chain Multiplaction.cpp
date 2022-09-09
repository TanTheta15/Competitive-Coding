/*    Matrix Chain Multiplication code both in Recursive and iterative way

*/
//Recursive Solution
int func(int arr[], int l, int r){
  if(l >= r) return 0; //Bounds Check
  
  int res = INT_MAX;
  int temp;
  
  for(int k = l; k < r; k++){
    temp = func9=(arr, l, k) + func(arr, k + 1, r) + arr[l] * arr[k] * arr[r];
    res = min(temp, res);
  }
  return res;
}

int matrixChainMultiplacation(int arr[], int n){
  return func(arr, 1, n - 1);
}

// Iterative Solution

int matrixChainMultiplication(vector<int> &arr, int n){
    int dp[n][n];
    for(int i = 1; i < n; i++){
        dp[i][i] = 0;
    }
    
    for(int i = n - 1; i >= 1; i--){
        for(int j = i + 1; j < n; j++){
            int mini = 1e9;
            for(int k = i; k < j; k++){
                int steps = arr[i] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if(steps < mini){
                    mini = steps;
                }
            }
            dp[i][j] = mini;
        }
    }
    return dp[0][n - 1];
}

