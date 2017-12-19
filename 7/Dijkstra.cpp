//2015004957 ¿”«ˆ≈√
#include<stdio.h>
#include<vector>
#pragma warning (disable : 4996)
using namespace std;

int n;

typedef struct{
	int price;
	int now;
} set;

set arr[5005];
int size;
int dist[5005];

vector<set> map[5005];

set Delete(void){
	int i = 1, child = 2;
	set Min, Last;
	Min = arr[1];
	Last = arr[size--];

	while (child <= size) {
		if (child < size&&arr[child].price >= arr[child + 1].price)
			child++;
		if (Last.price <= arr[child].price) break;

		arr[i] = arr[child];
		i = child;
		child *= 2;

	}
	arr[i] = Last;
	return Min;
}

void Insert(set a){
	int j;
	for (j = ++size; arr[j / 2].price > a.price; j /= 2){
		if (j / 2 == 0)
			break;
		arr[j] = arr[j / 2];
	}
	arr[j] = a;
}

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		dist[i] = 987654321;
		for (int j = 1; j <= b; j++){
			int c, d;
			scanf("%d %d", &c, &d);
			set temp;
			temp.price = d;
			temp.now = c;
			map[a].push_back(temp);
		}
	}

	dist[1] = 0;

	set temp;
	temp.price = 0;
	temp.now = 1;
	Insert(temp);

	while (size){
		set temp = Delete();

		int now = temp.now;
		int now_dis = temp.price;

		if (now_dis != dist[now])
			continue;
		for (int i = 0; i < map[now].size(); i++){
			int next = map[now][i].now;
			int next_dis = map[now][i].price;
			if (dist[next]>now_dis + next_dis){
				dist[next] = now_dis + next_dis;
				set tmp;
				tmp.price = dist[next];
				tmp.now = next;
				Insert(tmp);
			}
		}



	}

	int max = 0;
	for (int i = 1; i <= n; i++){
		if (max < dist[i]&&dist[i]!=987654321)
			max = dist[i];
	}

	printf("%d\n", max);
	return 0;
}