/*    Segment Tree Template

*/
#include<bits/stdc++.h> 
using namespace std;

const static int N = 1e3 + 10;
int seg[4 * N];
void build(int arr[], int low, int high, int ind){
    if(low == high){
        seg[ind] = arr[low];
        return ;
    }

    int mid = (low + high) >> 1;
    build(arr, low, mid, 2 * ind + 1);
    build(arr, mid + 1, high, 2 * ind + 2);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int low, int high, int ind, int ss, int se){
    if(low > se or high < ss){
        return 0;
    }

    if(low <= ss and high >= se){
        return seg[ind];
    }

    int mid = (ss + se) >> 1;
    int left = query(low, high, 2 * ind + 1, ss, mid);
    int right = query(low, high, 2 * ind + 2, mid + 1, se);
    return max(left, right);
}

int main(){
    int arr[N];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(arr, 0, n - 1, 0);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r, 0, 0, n - 1) << " ";
    }
}
