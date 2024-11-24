#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

typedef struct {
    int key;
} element;

typedef struct {
    element heap[100];
    int heap_size;
} HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
    int i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) {
            child++;
        }
        if (temp.key >= h->heap[child].key) {
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(element a[], int n) {
    int i;
    HeapType* h;

    h = create();
    init(h);
    for (i = 0; i < n; i++) {
        insert_max_heap(h, a[i]);
    }

    for (i = (n - 1); i >= 0; i--) {
        a[i] = delete_max_heap(h);
        for (int j = 1; j <= h->heap_size; j++) {
            printf("%d ", h->heap[j].key);
        }
        printf("[");
        for (int k = i; k < n; k++) {
            printf("%d ", a[k].key);
        }
        printf("]");
        printf("\n");
    }
    printf("\n정렬된 배열:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i].key);
    }
    free(h);
}

int main() {
    int i, n;
    element list[100];

    n = MAX_SIZE;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        list[i].key = rand() % 100;
    }

    printf("숫자의 개수: %d\n", MAX_SIZE);
    for (i = 0; i < n; i++) {
        printf("%d ", list[i].key);
    }
    printf("\n\n");

    heap_sort(list, n);

    printf("\n");
    return 0;
}
