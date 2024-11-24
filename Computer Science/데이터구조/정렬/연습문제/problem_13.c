#define MAX_SIZE 100
#define NAME_SIZE 20

typedef struct {
	int key;
	char name[NAME_SIZE];
} record;
record list[MAX_SIZE];


void insertion_sort(record list[], int n)
{
	int i, j;
	record record;
	for (i = 1; i < n; i++) {
		record = list[i];
		for (j = i - 1; j >= 0 && list[j].key > record.key; j--)
			list[j + 1] = list[j];
		list[j + 1] = record;
	}

}