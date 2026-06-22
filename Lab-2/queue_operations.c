// A2) Write a program to implement queue operations (INSERT, DELETE, DISPLAY).

// Queue is a linear data structure that follows the First In First Out (FIFO) principle. The operations that can be performed on a queue are:
#include <stdio.h>
#define MAX 5   // define Maximum size of queue

int queue[MAX];
int front = -1;
int rear = -1;

// insert(): Adds an element to the rear of the queue
void insert(){
    int value;
    // check for Queue Overflow
    if(rear == MAX - 1){
        printf("\nQueue Overflow!");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Element added..\n");
}

// delete(): Removes an element from the front of the queue
void delete(){
    // check for queue underflow
    if(front == -1 || front > rear){
        printf("\nQueue Underflow!");
        return;
    }
    printf("Deleted Element = %d\n", queue[front]);
    front++;
    // Reset queue when empty
    if(front > rear){
        front = -1;
        rear = -1;
    }
}

// display(): Displays all elements in the queue
void display(){
    int i;
    if(front == -1){
        printf("\nQueue is Empty!");
        return;
    }
    printf("\nQueue Elements:\n");
    for(i = front; i <= rear; i++){
        printf("%d\n", queue[i]);
    }
}

void main(){
    int choice;
    while (1)
    {
        printf("\n\nQUEUE OPERATIONS : 1) INSERT, 2) DELETE, 3) DISPLAY, 4) EXIT FROM PROGRAM");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program Ended.");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
}