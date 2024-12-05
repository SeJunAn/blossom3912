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

// 제산 함수를 사용한 해싱 함수
int hash_function(char *key) {
    int hash_value = 0;
    while (*key) {
        hash_value = (hash_value * 31 + *key++) % TABLE_SIZE;
    }
    return hash_value;
}

// 두 번째 해싱 함수 (제산 함수 사용)
int hash_function2(char *key) {
    return 1 + (hash_function(key) % (TABLE_SIZE - 1));  // 테이블 크기보다 작은 값을 반환
}

// 빈 항목인지 확인
int empty(element item) {
    return item.key[0] == '\0';  // 비어 있는 항목은 첫 문자가 '\0'임
}

// 두 항목이 같은지 비교
int equal(element item1, element item2) {
    return strcmp(item1.key, item2.key) == 0;
}

// 해싱 테이블 초기화
void init_table(element ht[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht[i].key[0] = '\0';  // 빈 문자열로 초기화
        ht[i].phone[0] = '\0';
    }
}

// 이중 해싱법으로 키와 전화번호 삽입
void hash_dh_add(element item, element ht[]) {
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function2(item.key);  // 두 번째 해싱 값으로 증가값 계산
    
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색키 중복: %s\n", item.key);
            return;
        }
        i = (i + inc) % TABLE_SIZE;  // 이중 해싱을 이용하여 위치 찾기
        if (i == hash_value) {
            fprintf(stderr, "테이블이 가득 찼습니다.\n");
            return;
        }
    }
    ht[i] = item;  // 해싱 테이블에 추가
}

// 해싱 테이블 출력
void hash_dh_print(element ht[]) {
    printf("\n==============\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!empty(ht[i])) {
            printf("[%d] %s\n", i, ht[i].key);  // 비어 있지 않으면 이름만 출력
        } else {
            printf("\n");  // 비어 있으면 빈 줄을 출력
        }
    }
    printf("==============\n");
}

// 이중 해싱법으로 키 탐색
void hash_dh_search(element item, element ht[]) {
    int i, hash_value, inc;
    hash_value = i = hash_function(item.key);
    inc = hash_function2(item.key);  // 두 번째 해싱 값으로 증가값 계산
    
    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            printf("탐색 %s    성공    %s\n", ht[i].key, ht[i].phone);
            return;
        }
        i = (i + inc) % TABLE_SIZE;  // 이중 해싱을 이용하여 위치 찾기
        if (i == hash_value) {
            printf("찾는 이름이 테이블에 없습니다: %s\n", item.key);
            return;
        }
    }
    printf("찾는 이름이 테이블에 없습니다: %s\n", item.key);
}

#define SIZE 10

// 해싱 테이블을 사용한 예제 
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
    for (int i = 0; i < SIZE; i++) {
        strcpy(e.key, names[i]);      // 이름 설정
        strcpy(e.phone, phones[i]);  // 전화번호 설정
        hash_dh_add(e, hash_table);  // 해싱 테이블에 추가 (이중 해싱법)
    }

    // 해싱 테이블 출력
    hash_dh_print(hash_table);

    // 이름으로 전화번호 탐색
    for (int i = 0; i < SIZE; i++) {
        strcpy(e.key, names[i]);
        hash_dh_search(e, hash_table);  // 이중 해싱법을 사용하여 탐색
    }

    return 0;
}
