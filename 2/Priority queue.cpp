//2015004957 ÀÓÇöÅÃ 
#include<stdio.h>
#pragma warning(disable : 4996)

int n, k;
int arr[100005];
int size;

int Delete(void){
	int i = 1, child = 2;
	int Max, Last;
	Max = arr[1];
	Last = arr[size--];;

	while (child <= size) {
		if (child < size&&arr[child] <= arr[child + 1])
			child++;
		if (Last >= arr[child]) break;

		arr[i] = arr[child];
		i = child;
		child *= 2;

	}
	arr[i] = Last;
	return Max;
}

void Insert(int a){
	int j;
	for (j = ++size; arr[j / 2] < a; j /= 2){
		if (j / 2 == 0)
			break;
		arr[j] = arr[j / 2];
	}
	arr[j] = a;
}

void Update(int key){
	int temp = 0;
	int child = key * 2;

	while (key != 1){
		if (arr[key]>arr[key / 2]){
			temp = arr[key / 2];
			arr[key / 2] = arr[key];
			arr[key] = temp;
			key /= 2;
		}
		else break;
	}

	while (child <= size){
		if (child < size&&arr[child] <= arr[child + 1])
			child++;
		if (arr[key] >= arr[child])
			break;

		temp = arr[key];
		arr[key] = arr[child];
		arr[child] = temp;
		key = child;
		child *= 2;
	}
}

int main(){
	while (1){
		int n;
		scanf("%d", &n);
		switch (n){
		case 0:
			printf("\n");
			for (int i = 1; i <= size; i++)
				printf("%d ", arr[i]);
			printf("\n");
			return 0;
		case 1:
			int temp;
			scanf("%d", &temp);
			Insert(temp);
			break;
		case 2:
			printf("%d ", Delete());
			break;
		case 3:
			int a, b;
			scanf("%d %d", &a, &b);
			arr[a] = b;
			Update(a);
			break;
		}
	}
	return 0;
}