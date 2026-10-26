#include <iostream>
using namespace std;

// Define the maximum capacity of the queue
const int MAX = 5;

// Queue class managing the static array
class queue
{
private:
    int a[MAX];  // Array to store queue elements
    int front;   // Index of the front element
    int rear;    // Index of the rear element

public:
    // Constructor to initialize an empty queue
    queue()
    {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is completely empty
    int empty(void)
    {
        // Queue is empty only when both front and rear are in their initial -1 state
        if (front == -1 && rear == -1)
        {
            return 1; // True
        }
        else
        {
            return 0; // False
        }
    }

    // Function to check if the queue has reached its maximum capacity
    int full(void)
    {
        // Queue is full when the rear index reaches the last position of the array
        if (rear == MAX - 1)
        {
            return 1; // True
        }
        else
        {
            return 0; // False
        }
    }

    // Function to insert an element at the rear of the queue
    void enqueue(int x)
    {
        // Prevent insertion if the array is already full (Overflow condition)
        if (full())
        {
            cout << "\nQueue is full";
            return;
        }

        // If inserting the very first element, update both front and rear pointers
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            // Otherwise, just move the rear pointer forward
            rear++;
        }

        // Insert the new data at the updated rear position
        a[rear] = x;
    }

    // Function to remove and return the element at the front of the queue
    int dequeue(void)
    {
        // Prevent deletion if the array is empty (Underflow condition)
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        // Store the value to be removed so it can be returned
        int x = a[front];

        // If there was only one element left in the queue, reset pointers to -1 after removing it
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            // Otherwise, simply move the front pointer forward to logicaly remove the element
            front++;
        }

        return x;
    }

    // Function to view the front element without removing it
    int peek(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        return a[front];
    }

    // Function to print all current elements in the queue
    void display(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return;
        }

        cout << "\nQueue elements:";
        // Iterate from the current front index to the current rear index
        for (int i = front; i <= rear; i++)
        {
            cout << "\t" << a[i];
        }
    }
};

int main()
{
    int x;
    queue q;

    // Enqueue elements up to the MAX capacity (5)
    q.enqueue(25);
    q.enqueue(57);
    q.enqueue(25);
    q.enqueue(82);
    q.enqueue(99);

    // Display the queue after initial insertions
    q.display();

    // Remove the first element (25) from the queue
    if (!q.empty())
    {
        x = q.dequeue();
        cout << "\nRemoved: " << x;
    }

    // Display the queue to show it after the deletion
    q.display();

    // Check the new front element (should be 57)
    x = q.peek();
    cout << "\nFront element is: " << x;

    return 0;
}


//PS C:\Mayur 233.c> cd "c:\Mayur 233.c\" ; if ($?) { g++ queue_using_array.cpp -o queue_using_array } ; if ($?) { .\queue_using_array }

//Queue elements: 25      57      25      82      99
//Removed: 25
//Queue elements: 57      25      82      99
//Front element is: 57
//PS C:\Mayur 233.c>