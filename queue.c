#include <stdio.h>
#define MAX 5  // Maximum size of the queue

int queue[MAX];  // Array to store queue elements
int front = -1, rear = -1;  // Pointers to track start and end of queue

// Function to add an element to the queue
void enqueue(int item) {
    // Check if queue is full (circular condition)
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot add %d.\n", item);
    }
    else {
        // If queue is empty, initialize front pointer
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;  // Circular increment
        queue[rear] = item;
        printf("Added %d to queue.\n", item);
    }
}

// Function to remove an element from the queue
int dequeue() {
    // Check if queue is empty
    if (front == -1) {
        printf("Queue Underflow! Queue is empty.\n");
        return -1;  // Return -1 to indicate failure
    }
    else {
        int item = queue[front];
        // If this was the last element, reset queue
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;  // Circular increment
        }
        printf("Removed %d from queue.\n", item);
        return item;
    }
}

// Function to display queue contents
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue contents (front to rear): ");
        int i = front;
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        printf("\n");
    }
}

int main() {
    // Test the queue operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  // Queue is now full
    
    display();  // Show all elements
    
    enqueue(60);  // Should show overflow
    
    dequeue();  // Remove first element
    dequeue();  // Remove second element
    
    display();  // Show remaining elements
    
    enqueue(60);  // Now we can add again (circular behavior)
    enqueue(70);
    
    display();  // Show all elements including new ones
    
    return 0;
}

