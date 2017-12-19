//2015004957 ¿”«ˆ≈√

#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
#include<algorithm>
#pragma warning(disable : 4996)

using namespace std;

int Max(int a, int b){
	if (a > b)
		return a;
	return b;
}

char A[505], B[505];
int dp[505][505];

int main(){
	scanf("%s", A);
	scanf("%s", B);

	int lenA = strlen(A);
	int lenB = strlen(B);

	for (int i = 0; i < lenA; i++){
		for (int j = 0; j < lenB; j++){
			if (A[i] == B[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = Max(dp[i + 1][j], dp[i][j + 1]);
		}
	}

	stack<int> st;

	for (;;){
		if (lenA*lenB == 0)
			break;
		if (dp[lenA - 1][lenB] < dp[lenA][lenB - 1])
			lenB--;
		else if (dp[lenA - 1][lenB] >dp[lenA][lenB - 1])
			lenA--;
		else if (dp[lenA][lenB] != dp[lenA - 1][lenB - 1]){
			st.push(lenA);
			lenA--; lenB--;
		}
		
		else
			lenA--;
	}

	while (!st.empty()){
		printf("%c", A[st.top()-1]);
		st.pop();
	}

	return 0;
}