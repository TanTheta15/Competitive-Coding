/*   SegMent Tree Template without Build Function

*/

void Update(ll st[], int ss, int se, int ind, int diff, int index){
    if(index > se or index < ss) return ;
    st[ind] = st[ind] + diff;
    if(ss < se){
        int mid = (ss + se) >> 1;
        Update(st, ss, mid, 2 * ind + 1, diff, index);
        Update(st, mid + 1, se, 2 * ind + 2, diff, index);
    }
}


void updateValue(int *arr, ll *st, int n, int index, int new_val) 
{
    // add code here
    int diff = new_val - arr[index];
    arr[index] = new_val;
    int ss = 0, se = n - 1, ind = 0;
    Update(st, ss, se, ind, diff, index);
}

//Function to return sum of elements in range from index qs (query start)
//to qe (query end).

ll sum(ll st[], int l, int r, int ss, int se, int ind){
    if(se < l or ss > r){
        return 0;
    }
    if(l <= ss and r >= se){
        return st[ind];
    }
    int mid = (ss + se) >> 1;
    
    return sum(st, l, r, ss, mid, 2 * ind + 1) + sum(st, l, r, mid + 1, se, 2 * ind + 2);
}

ll getsum(ll *st, int n, int l, int r)
{
    // add code here
    int ss = 0, se = n - 1, ind = 0;
    return sum(st, l, r, ss, se, ind);
}
