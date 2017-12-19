//2015004957 ¿”«ˆ≈√
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#pragma warning(disable : 4996)
using namespace std;

int n;
int s;
int k[30005];
char trash[5];
int value[30005];
int temp[30005];
int arr[30005];
int size = 0;
int T[30005];

int Delete(void){
	int i = 1, child = 2;
	int Min, Last;
	Min = arr[1];
	Last = arr[size--];;

	while (child <= size) {
		if (child < size&&arr[child] >= arr[child + 1])
			child++;
		if (Last <= arr[child]) break;

		arr[i] = arr[child];
		i = child;
		child *= 2;

	}
	arr[i] = Last;
	return Min;
}

void Insert(int a){
	int j;
	for (j = ++size; arr[j / 2] > a; j /= 2){
		if (j / 2 == 0)
			break;
		arr[j] = arr[j / 2];
	}
	arr[j] = a;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%s %d", trash, &k[i]);
	}

	sort(k + 1, k + n + 1);

	for (int i = 1; i <= n; i++){
		temp[i] = k[i];
		Insert(k[i]);

	}

	scanf("%d", &s);

	int cnt = 0, tmp = n;
	while (tmp > 0){
		tmp /= 2;
		cnt++;
	}

	printf("%d\n", cnt*s);

	while (size){
		int a, b;
		a = Delete();
		b = Delete();

		for (int i = 1; i <= n; i++){
			if (temp[i] == a || temp[i] == b)
				T[i]++;
		}

		if (size)
			Insert(a + b);

		for (int i = 1; i <= n; i++){
			if (temp[i] == a || temp[i] == b)
				temp[i] = a + b;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans += k[i] * T[i];
	}

	printf("%d\n", ans);
	return 0;
}