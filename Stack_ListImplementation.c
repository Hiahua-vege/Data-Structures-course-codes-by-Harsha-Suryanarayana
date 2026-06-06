#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;

//入栈
void Push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}

//出栈
void Pop() {
    struct Node* temp;
    if (top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

//以下为思考题，视频课中未给出，仿照课程代码自行写出

int Top() {
    if (top == NULL) {
        printf("Error: Stack empty\n");
        return -1;
    }
    return top->data;
}

int IsEmpty()
{
    if (top == NULL) return 1;
    return 0;
}

void Print() {
    struct Node* cur = top;
    printf("Stack: ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->link;
    }
    printf("\n");
}

int main() {
    Push(2);Print();
    Push(5);Print();
    Push(10);Print();
    Pop();Print();
    Push(12);Print();
    return 0;
}