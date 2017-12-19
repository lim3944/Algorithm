//2015004957 юсгЖец
#include<stdio.h>
#define MIN(x,y) ((x)<(y)?(x):(y))
#pragma warning(disable : 4996)

int root[1005];
int rank[1005];
int n;
int num = 1;

void Uni(int a, int b){
	int m = MIN(root[a], root[b]);

	int temp1 = root[a];
	int temp2 = root[b];

	for (int i = 1; i <= n; i++){
		if (root[i] == temp1 || root[i] == temp2)
			root[i] = m;
	}
}

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		root[i] = i;

	int a, b;
	while (scanf("%d %d", &a, &b) != EOF){
		if (root[a] != root[b]);
		Uni(a, b);
	}

	rank[1] = 1;

	for (int i = 1; i <= n; i++){
		if (rank[root[i]] == 0){
			rank[root[i]] = ++num;
		}
	}
	printf("%d\n", num);

	for (int i = 1; i <= n; i++)
		printf("%d\n", rank[root[i]]);

	return 0;
}

