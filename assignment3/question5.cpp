#include <iostream>
#include <stack>
using namespace std;

int main() {
    string postfix;
    cout << "Enter Postfix expression (single digit numbers only): ";
    cin >> postfix;

    stack<int> st;

    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0');   // convert char to int
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
        }
    }

    cout << "Result = " << st.top() << endl;
    return 0;
}
