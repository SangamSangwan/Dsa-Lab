#include <iostream>
#include <cstdlib>
#define MAX 5 
using namespace std;

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "\nStack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nStack Underflow! Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "\nStack is empty." << endl;
        } else {
            cout << "\nStack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "\nStack is empty. No top element." << endl;
        } else {
            cout << "\nTop element is: " << arr[top] << endl;
        }
    }
};

// Main menu
int main() {
    Stack st;
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                st.push(value);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                if (st.isEmpty())
                    cout << "Stack is Empty.\n";
                else
                    cout << "Stack is NOT Empty.\n";
                break;
            case 4:
                if (st.isFull())
                    cout << "Stack is Full.\n";
                else
                    cout << "Stack is NOT Full.\n";
                break;
            case 5:
                st.display();
                break;
            case 6:
                st.peek();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
