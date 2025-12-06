#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int ele) {
        if (!isFull()) {
            data[++top] = ele;
            cout << ele << " inserted into stack\n";
        } else {
            cout << "Stack Overflow!\n";
        }
    }

    int pop() {
        if (!isEmpty()) {
            return data[top--];
        } else {
            cout << "Stack Underflow!\n";
            return -1;
        }
    }

    int peek() {
        if (!isEmpty())
            return data[top];
        else
            return -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack (bottom to top): ";
        for (int i = 0; i <= top; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    int choice, ele;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> ele;
                s.push(ele);
                break;

            case 2: {
                int x = s.pop();
                if (x != -1)
                    cout << x << " popped from stack\n";
                break;
            }

            case 3: {
                int topEle = s.peek();
                if (topEle != -1)
                    cout << "Top element = " << topEle << "\n";
                else
                    cout << "Stack is empty\n";
                break;
            }

            case 4:
                cout << (s.isEmpty() ? "Stack is Empty\n" : "Stack is Not Empty\n");
                break;

            case 5:
                cout << (s.isFull() ? "Stack is Full\n" : "Stack is Not Full\n");
                break;

            case 6:
                s.display();
                break;

            case 7:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}