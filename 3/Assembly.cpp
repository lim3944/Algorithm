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

	queue<pair<int, int>> qu;
	stack<int> st;
	qu.push(make_pair(lenA, lenB));
	while (!qu.empty()){
		int n = qu.front().first;
		int m = qu.front().second;
		qu.pop();
		if (dp[n][m] == 0){
			break;
		}
		if (A[n - 1] == B[m - 1]){
			st.push(n - 1);
			qu.push(make_pair(n - 1, m - 1));
		}
		else if (dp[n][m] == dp[n - 1][m])
			qu.push(make_pair(n - 1, m));
		else
			qu.push(make_pair(n, m - 1));
	}

	while (!st.empty()){
		int n = st.top();
		st.pop();
		printf("%c", strA[n]);
	}
	return 0;
}