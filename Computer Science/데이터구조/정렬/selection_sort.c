#include <stdio.h>
#include <stdlib.h>

// t = x, y = x, y = t
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

#define MAX_SIZE 10

void selection_sort(int list[], int n){
    int least, temp;
    
    for(int i = 0; i < n - 1; i++){
        least = i;

        for(int j = i + 1; j < n; j++){
            if(list[j] < list[least]){
                SWAP(list[least], list[j], temp);
            }
        }
    }
}

int main(void){
    int list[MAX_SIZE];

    for(int i = 0; i < MAX_SIZE; i++){
        list[i] = rand() % 100;
    }

    selection_sort(list, MAX_SIZE);

    for(int i = 0; i < MAX_SIZE; i++){
        printf("%d ", list[i]);
    }

    return 0;
}