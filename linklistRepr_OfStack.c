// WAP to implement a linked stack
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *);
struct stack *pop(struct stack *);
struct stack *peek(struct stack *);
void display(struct stack *);
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
            case 1: top=push(top);
            printf("\n data is pushed");
            break;
            case 2: top=pop(top);
            break;
            case 3: top=peek(top);
            printf("\n that is at top");
            break;
            case 4: display(top);
            break;
        }
    }while(option!=5);
    return 0;
}
//           DISPLAY
void display(struct stack *top){
    if(top==NULL)
        printf("\n stack does not exist !");
    else if(top->next==NULL){
        printf("\n |_%d_|", top->data);
        printf("\n that's the stack");
    }
    else{
        while(top->next!=NULL){
            printf("\n |_%d_|", top->data);
            top=top->next;
        }
        printf("\n |_%d_|", top->data);
        printf("\n that's the stack");
    }
}
//           peek
struct stack *peek(struct stack *top){
    printf("\n ->%d", top->data);
    return top;
}
//           POP
struct stack *pop(struct stack *top){
    if(top==NULL){
        printf("\n UNDERFLOW !");
        return top;
    }
    struct stack *ptr;
    ptr=top;
    top=top->next;
    free(ptr);
    printf("\n data is poped");
    return top;
}
//           PUSH
struct stack *push(struct stack *top){
    struct stack *newNode;
    int val;
    printf("\n put the data : ");
    scanf("%d", &val);
    newNode=(struct stack *)malloc(sizeof(struct stack));
    newNode->data=val;
    if(top==NULL){
        newNode->next=NULL;
        top=newNode;
    }
    else{
        newNode->next=top;
        top=newNode;
    }
    return top;
}