#include <iostream>
#include <stack>

using namespace std;

void print_stack(stack<char> st) {
    while (not st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

int main() {
    stack<char> st1;
    char c;
    cin >> c;
    st1.push(c);
    while (c != '.') {
       if ((st1.top() == '(' and c == ')')
            or (st1.top() == '[' and c == ']')) st1.pop();
        else st1.push(c);
       
       cin >> c;
    }

    if (st1.size() == 1) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}