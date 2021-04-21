#include<stdio.h>
#include<stdlib.h>
void printf1(struct Stack &S);
struct Stack{
    int stacksize;
    int *top;
    int *base;
    };
void CreatStack(struct Stack &S){//建造空栈
    S.base=(int*)malloc(100*sizeof(struct Stack));
    if(!S.base)return;
    S.top=S.base;
    S.stacksize=100;
    }
int gettop(struct Stack S){//返回栈顶元素
    if(S.base==S.top)return 0;
    return *(S.top-1);
    }
void Push(struct Stack &S,int e){//压栈
    if(S.top-S.base>=S.stacksize){
    S.base=(int*)malloc(S.stacksize+10*sizeof(int));
    if(!S.base)printf("出错了1");return;
    S.top=S.base+S.stacksize;
    }
    S.stacksize+=10;
    *S.top++=e;
    }
/*int pop(struct Stack &S){//出栈
    if(S.base==S.top)return 0;
    S.top--;
    return *S.top;
    */
void pop(struct Stack &S){
    if(S.base==S.top)printf("出错了2");return ;
    S.top--;
    }

void printf1(struct Stack &S){//打印
    while(S.top!=S.base){
        int x;
         S.top--;
        printf("%d",*S.top);
        printf("\n");


        }
    }
/*void printf1(struct Stack &S){
     if(S.base==S.top)printf("出错了2");return ;
     while(S.top!=S.base){
         S.top--;
         printf("%d",gettop(S));
         }
    }*/
int main(void){
    struct Stack S;
    CreatStack(S);
    //printf("输入个数");
    Push(S,1);
    Push(S,2);
    Push(S,3);
    Push(S,4);
    Push(S,5);
    printf1(S);
   }
