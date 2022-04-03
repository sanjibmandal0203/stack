// i realy can't do that; the logic is not enaugh clear
#include<stdio.h>
#include<string.h>
#define max 20
int top=-1;
char stk[max];
void push(char);
char pop();
int main(){
    char exp[max], temp;
    int flag=1;
    printf("\n Enter the expression : ");
    gets(exp);
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            push(exp[i]);
        if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(top==-1)
                flag=0;
            else{
                temp=pop();
                if(exp[i]==')'&&(temp=='{'||temp=='['))
                    flag=0;
                if(exp[i]=='}'&&(temp=='('||temp=='['))
                    flag=0;
                if(exp[i]==']'&&(temp=='{'||temp=='('))
                    flag=0;
            }
        }  
    }
    if(top!=-1)
        flag=0;
    if(flag==0)
        printf("\n invalid expression !!");
    else
        printf("\n valid expression.:)");
    return 0;
}//           pop
char pop(){
    if(top==-1)
        printf("\n underflow !");
    else{
        return stk[top--];
    }
}
//           push
void push(char c){
    if(top==(max-1))
        printf("\n overflow !");
    else{
        top+=1;
        stk[top]=c;
    }
}
