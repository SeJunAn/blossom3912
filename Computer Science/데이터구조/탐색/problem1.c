#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 600000

int list[ARRAY_SIZE];  // 배열 선언

// 순차 탐색 함수
int seq_search2(int key, int low, int high) {
    int i;
    list[high + 1] = key;  // 보초값 설정
    for (i = low; list[i] != key; i++)
        ;
    if (i == (high + 1)) return -1;  // 탐색 실패
    return i;  // 탐색 성공
}

// 이진 탐색 함수
int search_binary2(int key, int low, int high) {
    int middle;
    while (low <= high) {  // 남아 있는 숫자가 있으면 반복
        middle = (low + high) / 2;
        if (key == list[middle]) return middle;  // 탐색 성공
        else if (key > list[middle])
            low = middle + 1;  // 오른쪽 탐색
        else
            high = middle - 1;  // 왼쪽 탐색
    }
    return -1;  // 탐색 실패
}

// 비교 함수 (qsort를 위한 오름차순 비교)
int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int main() {
    int key = rand() % 1000000;  // 0 ~ 999,999 랜덤 값
    clock_t start, end; 

    // 랜덤 값 배열에 저장
    srand(time(NULL));  // 랜덤 시드 초기화
    for (int i = 0; i < ARRAY_SIZE; i++) {
        list[i] = rand() % 1000000;  // 랜덤 값 생성 및 저장
    }

    // 순차 탐색 시간 측정
    start = clock();
    seq_search2(key, 0, ARRAY_SIZE - 1);  
    end = clock();
    printf("순차 탐색 : %.6f\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 3. 퀵 정렬
    qsort(list, ARRAY_SIZE, sizeof(int), compare);

    // 4. 이진 탐색 시간 측정
    start = clock();
    search_binary2(key, 0, ARRAY_SIZE - 1); 
    end = clock();
    printf("이진 탐색 : %.6f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
