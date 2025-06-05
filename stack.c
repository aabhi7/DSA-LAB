#include <stdio.h>

#define MAX 5 // Maximum size of the stack

int stack[MAX]; // Array to hold stack elements

int top = -1; // "top" tracks the top element

// Function to add (push) an element to the stack

void push(int item) {

if (top == MAX - 1) {

printf("Stack Overflow! Cannot push %d, stack is full.\n", item);

} else {

top++;

stack[top] = item;

printf("Pushed %d to the stack.\n", item);

}

}

int pop() {

if (top == -1) {

printf("Stack Underflow\n");

return -1; // Return -1

} else {

int item = stack[top]; // Get the top element

top--;

printf("Popped %d from the stack.\n", item);

return item; // Return

}

}

// Function to display all elements

void display() {

if (top == -1) {

printf("Stack is empty. Nothing to display.\n");

} else {

printf("Current Stack (Top to Bottom): ");

for (int i = top; i >= 0; i--) {

printf("%d ", stack[i]); // Print elements from top to bottom

}

printf("\n");

}

}

int main() {

// Test the stack

push(10); // Push 10

push(20); // Push 20

display(); // Show the stack

pop(); // Remove (20)

display(); // Show the stack

return 0;

}
