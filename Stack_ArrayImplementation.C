//栈的操作遵循“先进后出”原则，多数典型操作时间复杂度为常数
#include<stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        return;
    }
    A[++top] = x;
}

void Pop() {
    if (top == -1) {
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}

int Top() {
    return A[top];
}

void Print() {
    int i;
    printf("Stack: ");
    for(i = 0; i <= top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}//注意Print()函数并非栈的典型操作，只是用于测试例输出、便于理解

int main() {
    Push(2);Print();
    Push(5);Print();
    Push(10);Print();
    Pop();Print();
    Push(12);Print();
    return 0;
}