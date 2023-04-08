#include <stdio.h>
#include <stdlib.h>

struct node {
    int tag;            // 标记，0表示数据项，1表示子表
    union {
        int data;       // 数据项
        struct node* subList;   // 子表指针
    }u;
    struct node* next;  // 下一个节点指针
};

typedef struct node* List;   // 定义广义表类型

// 创建一个广义表节点
List createNode(int tag, int data, List subList, List nextNode) {
    List node = (List) malloc(sizeof(struct node));
    node->tag = tag;
    if(tag == 0) {
        node->u.data = data;
    } else if(tag == 1) {
        node->u.subList = subList;
    }
    node->next = nextNode;
    return node;
}

// 打印广义表
void printList(List L) {
    if(L == NULL) {
        printf("()");
        return;
    }
    printf("(");
    while(L != NULL) {
        if(L->tag == 0) {
            printf("%d", L->u.data);
            if(L->next != NULL && L->next->tag != 1) {
                printf(", ");
            }
        } else if(L->tag == 1) {
            printList(L->u.subList);
            if(L->next != NULL && L->next->tag != 1) {
                printf(", ");
            }
        }
        L = L->next;
    }
    printf(")");
}

int main() {
    List L = createNode(1, 0, NULL, createNode(0, 1, NULL, createNode(1, 0, createNode(0, 2, NULL, NULL), createNode(1, 0, createNode(0, 3, NULL, NULL), createNode(0, 4, NULL, NULL)))));
    // 创建广义表 (1, (2, 3), 4)
    printList(L);   // 输出：(1, (2, 3), 4)
    return 0;
}
