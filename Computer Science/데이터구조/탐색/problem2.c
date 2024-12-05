#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_SIZE 20       // 탐색키(이름)의 최대 길이
#define PHONE_SIZE 15     // 전화번호의 최대 길이
#define TABLE_SIZE 10     // 해싱 테이블의 크기

typedef struct {
    char key[KEY_SIZE];    // 이름 (해싱 키)
    char phone[PHONE_SIZE]; // 전화번호
} element;

element hash_table[TABLE_SIZE];  // 해싱 테이블

// 해싱 테이블 초기화
void init_table(element ht[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht[i].key[0] = '\0';  // 빈 문자열로 초기화
        ht[i].phone[0] = '\0';
    }
}

// 문자로 된 키를 숫자로 변환
int transform(char *key) {
    int number = 0;
    while (*key)
        number = 31 * number + *key++;
    return number;
}

// 해싱 함수 (제산 함수 사용)
int hash_function(char *key) {
    return transform(key) % TABLE_SIZE;
}

#define empty(item) (strlen(item.key) == 0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))

// 선형 조사법으로 키와 전화번호 삽입
void hash_lp_add(element item, element ht[]) {
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "중복된 이름이 있습니다: %s\n", item.key);
            exit(1);
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value) {
            fprintf(stderr, "테이블이 가득 찼습니다\n");
            exit(1);
        }
    }
    ht[i] = item;  // 해싱 테이블에 추가
}

// 선형 조사법으로 키 탐색
void hash_lp_search(element item, element ht[]) {
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            printf("찾은 이름: %s, 전화번호: %s, 위치: %d\n", ht[i].key, ht[i].phone, i);
            return;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == hash_value) {
            printf("찾는 이름이 테이블에 없습니다: %s\n", item.key);
            return;
        }
    }
    printf("찾는 이름이 테이블에 없습니다: %s\n", item.key);
}

// 해싱 테이블 출력
void hash_lp_print(element ht[]) {
    printf("\n===== 해싱 테이블 =====\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!empty(ht[i]))
            printf("[%d] 이름: %s, 전화번호: %s\n", i, ht[i].key, ht[i].phone);
        else
            printf("[%d] 비어 있음\n", i);
    }
    printf("=======================\n");
}

int main(void) {
    element e;
    char *names[] = { "Hong", "Kim", "Lee", "Nam", "Cheon", "Ahn", "Park", "Shin", "Oh", "Gu" };
    char *phones[] = { 
        "010-1234-0001", "010-1234-0002", "010-1234-0003", 
        "010-1234-0004", "010-1234-0005", "010-1234-0006", 
        "010-1234-0007", "010-1234-0008", "010-1234-0009", 
        "010-1234-0010" 
    };

    // 테이블 초기화
    init_table(hash_table);

    // 이름과 전화번호 삽입
    for (int i = 0; i < 10; i++) {
        strcpy(e.key, names[i]);      // 이름 설정
        strcpy(e.phone, phones[i]);  // 전화번호 설정
        hash_lp_add(e, hash_table);  // 해싱 테이블에 추가
    }

    // 해싱 테이블 출력
    hash_lp_print(hash_table);

    // 이름으로 전화번호 탐색
    for (int i = 0; i < 10; i++) {
        strcpy(e.key, names[i]);
        hash_lp_search(e, hash_table);
    }

    return 0;
}