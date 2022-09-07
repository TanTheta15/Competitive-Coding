const static int N = 1e5 + 10;
int parent[N], rank[N];

void make(int i)
{
	parent[i] = i;
	rank[i] = 1;
}

int find(int i){
	if(parent[i] == i) return i;
	else return parent[i] = find(parent[i]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;

	if(rank[b] > rank[a]) swap(a, b);
	parent[b] = a;
	rank[a] = rank[b] + 1;

}
