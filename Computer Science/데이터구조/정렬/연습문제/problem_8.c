#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x, y, t) ((t)=(x), (x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

void print_array(int list[], int high, int low)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", list[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (i == high)
			printf("high\t");
		else if (i == low)
			printf("low\t");
		else
			printf("\t");
	}
	printf("\n");
}

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		print_list(list, high, low);

		if (low < high) 
			SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	print_list(list, high, low);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void)
{
	n = MAX_SIZE;
	int list[] = { 67, 90, 57, 25, 84, 32, 73, 54 };
	
	quick_sort(list, 0, n - 1);

	
	return 0;
}