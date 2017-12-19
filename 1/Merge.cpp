//2015004957 ÀÓÇöÅÃ 
#include<stdio.h>
#define MAX 987654321



int arr[100005], TmpArr[100005];
int n;

void Merge(int L, int R, int RE){
	int i, LeftEnd, num, temp;
	LeftEnd = R - 1;
	temp = L;
	num = RE - L + 1;

	while (L <= LeftEnd && R <= RE) {
		if (arr[L] >= arr[R]) TmpArr[temp++] = arr[L++];
		else TmpArr[temp++] = arr[R++];
	}

	while (L <= LeftEnd)
		TmpArr[temp++] = arr[L++];

	while (R <= RE)
		TmpArr[temp++] = arr[R++];

	for (i = 0; i<num; i++, RE--)
		arr[RE] = TmpArr[RE];

}

void MSort(int L, int R){
	int Center;
	if (L < R){
		Center = (L + R) / 2;
		MSort(L, Center);
		MSort(Center + 1, R);
		Merge(L, Center + 1, R);
	}
}

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	MSort(1, n);

	for (int i = 1; i <= n; i++)
		printf("%d\n", arr[i]);

	return 0;
}
