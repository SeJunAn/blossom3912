#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 6
#define SWAP(x, y, t) ((t)=(x), (x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;


void insertion_sort(int list[], int n)
{
	int i, j, key;

	for (i = 0; i <= n; i++) {
		printf("( ");
		for (int k = 0; k < i; k++){
            printf("%d ", list[k]);
        }
		printf(")     ");

		printf("( ");
		for (int k = i; k < n; k++){
            printf("%d ", list[k]);
        }
		printf(")\n");

		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--){
            list[j + 1] = list[j];
        }
		list[j + 1] = key;
	}
}

int main(void)
{
	n = MAX_SIZE;
	for (int i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }

	insertion_sort(list, n);

	return 0;
}