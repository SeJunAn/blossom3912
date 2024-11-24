#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
	int i, j, least, temp;

	printf("( )    ");
	printf("( ");
	for (int i = 0; i < n; i++){
        printf("%d ", list[i]);
    }
	printf(")\n");

	for (i = 0; i < n; i++) {
		least = i;
		for (j = i + 1; j < n; j++){
            if (list[j] < list[least]) least = j;
        }
		SWAP(list[i], list[least], temp);

		printf("( ");
		for (int k = 0; k <= i; k++){
            printf("%d ", list[k]);
        }
		printf(")     ");

		printf("(");
		for (int k = i + 1; k < n; k++){
            printf("%d ", list[k]);
        }
		printf(")\n");
	}	
}

int main(void)
{
	n = MAX_SIZE;
	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);

	selection_sort(list, n);

	return 0;
}