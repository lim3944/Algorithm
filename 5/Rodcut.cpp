//2015004957 ÀÓÇöÅÃ
#include<stdio.h>
#pragma warning(disable : 4996)

int n;
int p[105];
int r[105];
int s[105];
int max = 0;

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);

	for (int j = 1; j <= n; j++){
		int q = -987654321;
		for (int i = 1; i <= j; i++){
			if (q < p[i] + r[j - i]){
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
		if (max < q)
			max = q;
	}

	printf("%d\n", max);

	while (n > 0){
		printf("%d ", s[n]);
		n -= s[n];
	}
	return 0;
}