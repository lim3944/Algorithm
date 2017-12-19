//2015004957 ÀÓÇöÅÃ 
#include<stdio.h>
#pragma warning(disable : 4996)

int n, k;
int arr[100005];

int Delete(void){
	int i, C;
	int Max, Last;
	Max = arr[1];
	Last = arr[n--];;

	for (i = 1; i * 2 <= n; i = C){
		C = i * 2;
		if (C != n&&arr[C + 1]>arr[C])
			C++;
		if (Last<arr[C])
			arr[i] = arr[C];
		else
			break;
	}
	arr[i] = Last;
	return Max;
}

int main(){
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);

		int j;
		for (j = i; arr[j / 2] < a; j /= 2){
			if (j / 2 == 0)
				break;
			arr[j] = arr[j / 2];
		}
		arr[j] = a;
	}

	while (k--){
		int a = Delete();
		printf("%d ", a);
	}

	printf("\n");

	for (int i = 1; i <= n; i++)
		printf("%d ", arr[i]);

	return 0;
}