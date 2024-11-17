// temp file

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

// t = x, y = x, y = t
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

void buble_sort(int list[], int n){
    int i, j, temp;
    for(i = n - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(list[j] > list[j + 1]){
                SWAP(list[j], list[j + 1], temp);
            }
        }
    }
}

int main(void){
    int list[MAX_SIZE];

    srand(time(NULL));  // 랜덤 시드 설정

    for(int i = 0; i < MAX_SIZE; i++){
        list[i] = rand() % 100;
    }

    buble_sort(list, MAX_SIZE);

    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", list[i]);
    }

    return 0;
}