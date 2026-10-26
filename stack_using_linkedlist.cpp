#include <iostream>
using namespace std;

// Node class for the linked list
class node {
public:
    int data;
    node *next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

// Stack class managing the linked list
class stack {
private:
    node *top;

public:
// Initialize an empty stack
    stack() {
        top = NULL;
    }

    // Check if the stack is empty
    int empty() {
        if (top == NULL) {
            return 1;
        } else {
            return 0;
        }
    }

    // Add a new element to the top
    void push(int x) {
        node *p = new node(x);
        p->next = top;
        top = p;
    }

    // Remove and return the top element
    int pop(void) {
        int x = top->data;
        node *p = top;
        top = top->next;
        delete p;
        return x;
    }

    // View the top element without removing it
    int peek() {
        return top->data;
    }

    // Print all elements from top to bottom
    void display() {
        node *q = top;
        while (q != NULL) {
            cout << endl << q->data;
            q = q->next;
        }
    }
};

int main() {
    int x;
    stack s;

    s.push(990);
    s.push(810);
    s.push(333);
    s.push(578);
    s.push(100);
    s.push(220);
    
    s.display();

    if (!s.empty()) {
        x = s.pop();
        cout << endl << "Removed" << x;
    }
    
    s.display();

    x = s.peek();
    cout << endl << "Top Element is:" << x;

    return 0;
}



//PS D:\Mayur> cd "d:\Mayur\" ; if ($?) { g++ stack_using_linkedlist.cpp -o stack_using_linkedlist } ; if ($?) { .\stack_using_linkedlist }

//220
//100
//578
//333
//810
//990
//Removed220
//100
//578
//333
//810
//990
//Top Element is:100