#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Nhap so nguyen: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

int enQueue(Queue* q) {
    Node* newNode = createNode();
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int printQueue(Queue* q) {
    Node* temp = q->front;
    printf("queue = {\n  front->");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n  rear->");
    if (q->rear != NULL)
        printf("%d->NULL\n", q->rear->data);
    else
        printf("NULL\n");
    printf("}\n\n");
}

int main() {
    Queue* q = createQueue();
    enQueue(q);
    printQueue(q);
    return 0;
}