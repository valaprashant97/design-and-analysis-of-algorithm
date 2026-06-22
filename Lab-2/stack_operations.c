// A1) Write a program to implement stack operations (PUSH, POP, PEEP, CHANGE & DISPLAY).

// Stack is a linear data structure that follows the Last In First Out (LIFO) principle. The operations that can be performed on a stack are:
#include <stdio.h>
#define MAX 5   // define Maximum size of stack

int stack[MAX];
int top = -1;  // Stack empty

// push(): Adds an element to the top of the stack
void push()
{
    int value;
    // if Check for Stack Overflow
    if(top == MAX - 1)
    {
        printf("\nStack Overflow!");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);
    top++;
    stack[top] = value;
    printf("Value inserted successfully.\n");
}

// pop(): Removes an element from the top of the stack
void pop()
{
    // if Check for Stack Underflow
    if(top == -1)
    {
        printf("\nStack Underflow!");
        return;
    }
    printf("Deleted Element = %d\n", stack[top]);
    top--;
}

// peep(): Displays an element at a specific position in the stack
void peep()
{
    int position;
    // if Check for Empty Stack
    if(top == -1)
    {
        printf("\nStack is Empty!");
        return;
    }
    printf("Enter position from TOP: ");
    scanf("%d", &position);

    // if Check for valid position
    if(position <= 0 || position > top + 1)
    {
        printf("Invalid Position!\n");
        return;
    }
    // Formula:
    // index = top - position + 1
    printf("Element = %d\n", stack[top - position + 1]);
}

// change(): Changes the value of an element at a specific position in the stack
void change()
{
    int position, value;
    if(top == -1)
    {
        printf("\nStack is Empty!");
        return;
    }
    printf("Enter position from TOP: ");
    scanf("%d", &position);
    if(position <= 0 || position > top + 1)
    {
        printf("Invalid Position!\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &value);
    // Change value
    stack[top - position + 1] = value;
    printf("Value changed successfully.\n");
}

// display(): Displays all elements in the stack
void display()
{
    int i;
    if(top == -1)
    {
        printf("\nStack is Empty!");
        return;
    }
    printf("\nStack Elements:\n");
    // Print from top to bottom
    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    while (1)  // Infinite loop for menu-driven program
    {
    int choice;
    printf("\n\nSTACK OPERATIONS : 1) PUSH, 2) POP, 3) PEEP, 4) CHANGE, 5) DISPLAY, 6) EXIT");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            change();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}
}
// cd .\Lab-1
// gcc hello.c -o hello.exe
// .\hello.exe