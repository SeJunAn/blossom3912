/*
개요: 입력 데이터를 정렬한다
버블 정렬, 선택 정렬, 삽입정렬, 셀정렬을 구현한다.
이번 과제는 2가지이다.
[문제1] 정렬단계 출력
데이터는 랜덤함수를 이용하여 생성
데이터의 범위는 [1, 100]
데이터의 개수는 10개
프로그램 구현 결과를 출력할 때 정렬이 되는 단계(step)를 보이도록 한다.
            (예)

            -----------------------

            버블정렬

            입력데이터: 9 5 8 4 1

            Step 1: 5 9 8 4 1

            Step 2: 5 8 9 4 1

            …

            정렬데이터: 1 4 5 8 9

            ------------------------

            선택정렬

            …

[문제2] 처리시간 계산
데이터는 랜덤함수를 이용하여 생성
데이터의 범위는 [1, 1,000,000]
데이터의 개수는 50,000개
구현 후 각 정렬 알고리즘의 수행 시간 비교
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 50000

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

void insertion_sort(int list[], int n){
    int i, j, key;
    for(i = 1; i < n; i++){
        key = list[i];
        for(j = i - 1; j >= 0 && list[j] > key; j--){
            list[j + 1] = list[j];
        }
        list[j + 1] = key;
    }
}

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

void inc_insertion_sort(int list[], int first, int last, int gap){
    int i, j, key;

    for(i = first + gap; i <= last; i = i + gap){
        key = list[i];
        for(j = i - gap; j >= first && key < list[j]; j = j - gap){
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n){
    int i, gap;

    for(gap = n / 2; gap > 0; gap = gap / 2){
        if((gap % 2) == 0){
            gap++;
        }
        for(i = 0; i < gap; i++){
            inc_insertion_sort(list, i, n - 1, gap);
        }
        
    }
}

int main(void){
    int buble_list[MAX_SIZE];
    int selection_list[MAX_SIZE];
    int insertion_list[MAX_SIZE];
    int shell_list[MAX_SIZE];
    clock_t start, end;
    double duration;

    srand(time(NULL));  // 랜덤 시드 설정

    for(int i = 0; i < MAX_SIZE; i++){
        int number = (rand() % 1000000) + 1;
        buble_list[i] = number;
        selection_list[i] = number;
        insertion_list[i] = number;
        shell_list[i] = number;
    }

    // 정렬 별 소요시간 측정 및 출력
    start = clock();
    buble_sort(buble_list, MAX_SIZE);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("버블정렬 시간: %.4f 초\n", duration);

    start = clock();
    selection_sort(selection_list, MAX_SIZE);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("선택정렬 시간: %.4f 초\n", duration);

    // 삽입 정렬 시간 측정
    start = clock();
    insertion_sort(insertion_list, MAX_SIZE);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("삽입정렬 시간: %4f 초\n", duration);

    // 셸 정렬 시간 측정
    start = clock();
    shell_sort(shell_list, MAX_SIZE);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("셸 정렬 시간: %.4f 초\n", duration);

    return 0;
}