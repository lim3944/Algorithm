//2015004957 ¿”«ˆ≈√
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<functional>
#pragma warning(disable : 4996)

typedef struct Node{
	int value;
	int index;
	int left;
	int right;
}Node;

int n;
int s;
int k;
char trash[5];
Node arr[30005];
Node T[300005];
int size = 0;
int sum = 0;
int root = 0;

Node Delete(void){
	int i = 1, child = 2;
	Node Min, Last;
	Min = arr[1];
	Last = arr[size--];

	while (child <= size) {
		if (child < size&&arr[child].value >= arr[child + 1].value)
			child++;
		if (Last.value <= arr[child].value) break;

		arr[i] = arr[child];
		i = child;
		child *= 2;

	}
	arr[i] = Last;
	return Min;
}

void Insert(Node a){
	int j;
	for (j = ++size; arr[j / 2].value > a.value; j /= 2)
		arr[j] = arr[j / 2];
	arr[j] = a;
}

void dfs(int now, int depth) {
	if (now == -1) return;
	if (T[now].left == -1 && T[now].right == -1) {
		sum += depth*T[now].value;
		return;
	}

	if (T[now].left != -1) dfs(T[now].left, depth + 1);
	if (T[now].right != -1) dfs(T[now].right, depth + 1);
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%s %d", trash, &k);

		Node temp;
		temp.index = ++root;
		temp.value = k;
		temp.left = -1;
		temp.right = -1;

		Insert(temp);
		T[root] = temp;
	}

	scanf("%d", &s);

	int cnt = 0, tmp = n;
	while (tmp > 0){
		tmp /= 2;
		cnt++;
	}
	if (cnt == 0) cnt++;

	printf("%d\n", cnt*s);

	while (size>1){
		Node a, b, temp;
		a = Delete();
		b = Delete();

		temp.index = ++root;
		temp.left = a.index;
		temp.right = b.index;
		temp.value = a.value + b.value;

		Insert(temp);
		T[root] = temp;
	}

	dfs(arr[1].index, 0);

	if (root == 1) printf("%d\n", s);

	printf("%d\n", sum);
	return 0;
}