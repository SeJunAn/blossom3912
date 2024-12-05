#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define PHONE_SIZE 15

typedef struct {
    char key[20];   // 이름
    char phone[PHONE_SIZE]; // 전화번호
} element;

struct list {
    element item;
    struct list *link;
};

struct list *hash_table[TABLE_SIZE];

// 제산 함수를 사용한 해싱 함수
int hash_function(char *key) {
    int hash_value = 0;
    while (*key) {
        hash_value = (hash_value * 31 + *key++) % TABLE_SIZE;
    }
    return hash_value;
}

// 체인법을 이용하여 테이블에 키를 삽입
void hash_chain_add(element item, struct list *ht[]) {
    int hash_value = hash_function(item.key);
    struct list *ptr;
    struct list *node_before = NULL, *node = ht[hash_value];
    for (; node; node_before = node, node = node->link) {
        if (strcmp(node->item.key, item.key) == 0) {
            fprintf(stderr, "이미 탐색키가 저장되어 있음: %s\n", item.key);
            return;
        }
    }
    ptr = (struct list *)malloc(sizeof(struct list));
    ptr->item = item;
    ptr->link = NULL;
    if (node_before)
        node_before->link = ptr;
    else
        ht[hash_value] = ptr;
}

// 체인법을 이용하여 테이블에 저장된 키를 탐색
void hash_chain_search(element item, struct list *ht[]) {
    struct list *node;
    int hash_value = hash_function(item.key);
    for (node = ht[hash_value]; node; node = node->link) {
        if (strcmp(node->item.key, item.key) == 0) {
            printf("탐색 %s    성공    %s\n", node->item.key, node->item.phone);
            return;
        }
    }
    printf("키를 찾지 못했음: %s\n", item.key);
}

// 해싱 테이블을 출력
void hash_chain_print(struct list *ht[]) {
    struct list *node;
    printf("\n===== 해싱 테이블 =====\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]->", i);  // 인덱스 출력
        if (ht[i]) {
            for (node = ht[i]; node; node = node->link) {
                printf("%s->", node->item.key);  // 연결 리스트에 있는 항목 출력
            }
        }
        printf("\n");  // 각 인덱스에 대해 새 줄 출력
    }
    printf("=======================\n");
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
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }

    // 이름과 전화번호 삽입
    for (int i = 0; i < SIZE; i++) {
        strcpy(e.key, names[i]);      // 이름 설정
        strcpy(e.phone, phones[i]);  // 전화번호 설정
        hash_chain_add(e, hash_table);  // 해싱 테이블에 추가
    }

    // 해싱 테이블 출력 (최종 출력)
    hash_chain_print(hash_table);

    // 이름으로 전화번호 탐색
    for (int i = 0; i < SIZE; i++) {
        strcpy(e.key, names[i]);
        hash_chain_search(e, hash_table);  // 체이닝법을 사용하여 탐색
    }

    return 0;
}
