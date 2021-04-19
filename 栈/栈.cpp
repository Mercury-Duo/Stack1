#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* Next;
};
struct Strack {
    int size;
    struct Node* StrackTop;
};
//初始化节点
struct Node* CreatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->Next = NULL;
    return newNode;
}//初始化栈
struct Strack* CreatStack() {
    struct Strack* newStrack = (struct Strack*)malloc(sizeof(struct Strack));
    newStrack->size = 0;
    newStrack->StrackTop = NULL;
    return newStrack;
}//压栈
void push(struct Strack* Strack, int data) {
    struct Node* newNode = CreatNode(data);
    newNode->Next = Strack->StrackTop;
    Strack->StrackTop = newNode;
    Strack->size++;
}//获取栈顶
int top(struct Strack* Strack1) {
    while (Strack1->size != 0) {
        return Strack1->StrackTop->data;
    }
}
//出栈
void pop(struct Strack* Strack1) {
    struct Node* node1 = Strack1->StrackTop->Next;
    free(Strack1->StrackTop);
    Strack1->StrackTop = node1;
    Strack1->size--;
}
//判断栈是否为空
int empty(struct Strack* Strack1) {
    if (Strack1->size == 0)return 0;
    return 1;
}
int main()
{
    struct Strack* myStrack;
    myStrack = CreatStack();
    push(myStrack, 1);
    push(myStrack, 2);
    push(myStrack, 3);
    push(myStrack, 4);
    push(myStrack, 5);
    push(myStrack, 6);
    push(myStrack, 7);
    push(myStrack, 8);
    push(myStrack, 9);
    while (empty(myStrack)) {
        printf("%d", top(myStrack));
        printf("\n");
        pop(myStrack);//出栈
    }
}

