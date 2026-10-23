#include <stdio.h>
#include <stdlib.h>
typedef struct node {
     char data; struct node *next;
} node;
typedef struct stack {
    node *top;
} stack;
void initStack(stack *s) {
     s->top = NULL;
}
int isEmpty(stack s) {
     return s.top == NULL;
}
void push(stack *s, char value) {
     node *newnode = malloc(sizeof(node));
if (newnode == NULL)
    return;

newnode->data = value;
newnode->next = s->top;
s->top = newnode;
}
int pop(stack *s) {
     if (isEmpty(*s)) return '\0';
node *temp = s->top;
char value = temp->data;
s->top = temp->next;
free(temp);

return value;
}
int peek(stack s) {
     if (isEmpty(s)) return '\0';
return s.top->data;
}
int evaluate(char exp[]){
stack s;
initStack(&s);
int i=0;
int a,b;
char c;
while (exp[i]!='\0'){
    c=exp[i];
if (c>='0'&& c<='9'){
    push(&s,c);
}
else{
    b=pop(&s)-'0';
    a=pop(&s)-'0';
    switch(c){
        case'+':
        push(&s,a+b+'0');
        break;
    case'-':
        push(&s,a-b+'0');
        break;
    case'*':
        push(&s,a*b+'0');
        break;
    case'/':
         push(&s,a/b+'0');
         break;
    }
}
i++;
}
return pop(&s)-'0';
}
int main() {
    stack s;
    char exp[]="63+2*4/";
    initStack(&s);
push(&s, 'A');
push(&s, 'B');
push(&s, 'C');

printf("Top: %c\n", peek(s));
printf("Pop: %c\n", pop(&s));
printf("Pop: %c\n", pop(&s));
printf("result=%d\n",evaluate(exp));

return 0;
}
