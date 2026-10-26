#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class node
{
public:
    int data; // Data stored in the node
    node *next; // Pointer to the next node

    // Constructor to initialize a new node
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Queue class managing the linked list
class queue
{
private:
    node *front;
    node *rear;

public:
// Constructor to initialize an empty queue
    queue()
    {
        front = rear = NULL;
    }

    // Function to check if the queue is empty
    int empty(void)
    {
        if (front == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // Function to return the front element without removing it
    int peek(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        return front->data;
    }

    // Function to add an element to the rear of the queue
    void enqueue(int x)
    {
        node *p = new node(x);

        if (front == NULL)
        {
            front = p;
            rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }

    // Function to remove and return the front element of the queue
    int dequeue(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        int x = front->data;
        node *p = front;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete p;

        return x;
    }

    // Function to print all elements in the queue
    void display(void)
    {
        node *q = front;

        cout << "\nQueue elements: ";

        while (q != NULL)
        {
            cout << "\t" << q->data;
            q = q->next;
        }
    }
};

int main()
{
    int x;
    queue q;

    q.enqueue(27);
    q.enqueue(34);
    q.enqueue(42);
    q.enqueue(58);
    q.enqueue(65);
    q.enqueue(70);

    q.display();

    if (!q.empty())
    {
        x = q.dequeue();
        cout << "\nRemoved: " << x;
    }

    q.display();

    x = q.peek();
    cout << "\nFront element is: " << x;

    return 0;
}


//PS C:\Mayur 233.c> cd "c:\Mayur 233.c\" ; if ($?) { g++ queue_using_linkedlist.cpp -o queue_using_linkedlist } ; if ($?) { .\queue_using_linkedlist }

//Queue elements:         27      34      42      58      65      70
//Removed: 27
//Queue elements:         34      42      58      65      70
//Front element is: 34