//2015004957 ÀÓÇöÅÃ 
#include<stdio.h>

int n;
int arr[30005];
int key;

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	
	for (int i = 2; i <= n; i++){
		key = arr[i];
		int j = i - 1;
		while (j > 0 && arr[j] < key){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", arr[i]);

	return 0;
}