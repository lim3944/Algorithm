//2015003947 ¿”«ˆ≈√
#include<stdio.h>
#pragma warning(disable : 4996)

int n, m;

int a[100005], b[100005];
int sizeA, sizeB;

int Delete(int* a,int size){
	int i, C;
	int Max, Last;
	Max = a[1];
	Last = a[size--];;

	for (i = 1; i * 2 <= size; i = C){
		C = i * 2;
		if (C != size&&a[C + 1]>a[C])
			C++;
		if (Last<a[C])
			a[i] = a[C];
		else
			break;
	}
	a[i] = Last;
	return Max;
}

int Insert(int* a,int size,int value){
	int j;
	for (j = ++size; a[j / 2] < value; j /= 2){
		if (j / 2 == 0)
			break;
		a[j] = a[j / 2];
	}
	a[j] = value;
	return size;
}

int main(){
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		int value;
		scanf("%d", &value);
		sizeA=Insert(a, sizeA, value);
	}

	for (int i = 1; i <= m; i++){
		int value;
		scanf("%d", &value);
		sizeB=Insert(b, sizeB, value);
	}
	
	for (int i = 0; i < n; i++)
		a[n - i] = Delete(a,sizeA--);
	for (int i = 0; i < m; i++)
		b[m - i] = Delete(b,sizeB--);

	int num = 0;

	int i = 1, j = 1;

	while (1){
		if (i>n || j>m)
			break;
		if (a[i] == b[j]){
			num++;
			i++;
			j++;
		}
		else if (a[i]>b[j])
			j++;
		else
			i++;
	}

	printf("%d\n", num);
	return 0;
		
}
