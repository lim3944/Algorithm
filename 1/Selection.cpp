//2015004957 ÀÓÇöÅÃ 
#include<stdio.h>
#define MAX 987654321


int n, m;
int arr[30005];
int key;

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= m; i++){
		int min = MAX;
		int pos;
		for (int j = i; j <= n; j++){
			if (min > arr[j]){
				min = arr[j];
				pos = j;
			}
		}
		arr[pos] = arr[i];
		arr[i] = min;
	}


	for (int i = 1; i <= n; i++)
		printf("%d\n", arr[i]);

	return 0;
}