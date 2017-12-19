//2015004957 ÀÓÇöÅÃ
#include<stdio.h>
#pragma warning(disable : 4996)

int n, m, k;

int arr[100005];
int a[100005];
int b[100005];

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= k; i++)
		scanf("%d %d", &a[i], &b[i]);

	for (int i = 1; i <= n; i++){
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}

	for (int i = 2; i <= m; i++)
		arr[i] += arr[i - 1];



	for (int i = 1; i <= k; i++){
		printf("%d\n", arr[b[i]] - arr[a[i] - 1]);
	}

	return 0;

}