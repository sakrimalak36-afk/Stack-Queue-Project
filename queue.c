#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int customerNumber;
    struct node * next;
}Node;

typedef struct Queue{
    Node*front;
    Node*rear;
}Queue;
void initQueue(Queue*q){
    q->front=NULL;
    q->rear=NULL;
}
int isEmpty(Queue*q){
 return q->front==NULL;
}
void enqueue(Queue*q,int number){
 Node*newNode=malloc(sizeof(Node));
 newNode->customerNumber=number;
 newNode->next=NULL;
  if(q->rear==NULL){
   q->front=newNode;
   q->rear=newNode;
 }else{
     q->rear->next = newNode;
     q->rear=newNode;
   }
 }
int dequeue(Queue*q){
  if(isEmpty(q))
    return-1;
  Node*temp=q->front;
  int number=temp->customerNumber;
  q->front=q->front->next;
  if (q->front==NULL)
    q->rear=NULL;

  free(temp);
  return number;
}
int peek(Queue*q){
 if(isEmpty(q))
    return -1;
 return q->front->customerNumber;
}
int main(){
    Queue q;
    int choice,number;
    initQueue(&q);
    do{
     printf("\n1.add customer");
     printf("\n2.serve customer");
     printf("\n3.despley first customer");
     printf("\n4.despley all customer");
     printf("\n0.Exit");
     printf("\nchoice:");
     scanf("%d",&choice);

        if (choice == 1) {
            printf("Enter customer number: ");
            scanf("%d", &number);

            enqueue(&q, number);
            printf("Customer %d arrived.\n", number);
        }

        else if (choice == 2) {
            if (isEmpty(&q)) {
                printf("Queue is empty.\n");
            } else {
                number = dequeue(&q);
                printf("Customer %d is being served.\n", number);
            }
        }

        else if (choice == 3) {
            if (isEmpty(&q)) {
                printf("Queue is empty.\n");
            } else {
                printf("First customer: %d\n", peek(&q));
            }
        }

        else if (choice == 4) {
            Node* temp = q.front;

            if (temp == NULL) {
                printf("Queue is empty.\n");
            } else {
                printf("Customers: ");

                while (temp != NULL) {
                    printf("%d ", temp->customerNumber);
                    temp = temp->next;
                }

                printf("\n");
            }
        }

    } while (choice != 0);

    while (!isEmpty(&q)) {
        number = dequeue(&q);
        printf("Customer %d is being served.\n", number);
    }

    printf("Queue is empty.\n");

    return 0;
}

