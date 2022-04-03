// WAP to perform push, pop and peek operations on a stack
#include<stdio.h>
int max=6;
int stk[6], top=-1;
void push(int *);
void pop(int *);
void peek (int *);
void display(int *);
int main(){
    int option;
    do{
        printf("\n\n -----MAIN MENU-----");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1: push(stk);
            break;
            case 2: pop(stk);
            break;
            case 3: peek(stk);
            break;
            case 4: display(stk);
            break;
        }
    }while(option!=5);
    return 0;
}
//                    DISPLAY
void display(int *stk){
    if(top==-1){
        printf("\n no data avalible.");
        return;
    }
    int i;
    for(i=top;i>=0;i--)
        printf("\n |_%d_|", stk[i]);
}
//                    PEEK
void peek(int *stk){
    printf("\n ->%d", stk[top]);
}
//                    POP
void pop(int *stk){
    if(top==-1){
        printf("\n underflow!!");
        return;
    }
    top--;
}
//                    PUSH
void push(int *stk){
    if(top==max-1){
        printf("\n overflow!!");
        return;
    }
    int val;
    printf("\n Enter the data : ");
    scanf("%d", &val);
    top++;
    stk[top]=val;
}