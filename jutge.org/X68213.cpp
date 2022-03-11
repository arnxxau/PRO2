#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void return_book(vector<stack<string>>& library) {
    string s;
    cin >> s;
    int n;
    cin >> n;
    --n;
    library[n].push(s);
}

void delete_books(vector<stack<string>>& library) {
    int n_stack, n;
    cin >> n >> n_stack;
    --n_stack;
    for (int i = 0; i < n; ++i) library[n_stack].pop();
}

void write_stack(vector<stack<string>> library) {
    int n;
    cin >> n;
    --n;
    cout << "Pila de la categoria " << n + 1 << endl;
    while (not library[n].empty()) {
        cout << library[n].top() << endl;
        library[n].pop();
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<stack<string>> library (n);

    cin >> n;
    while (n != -4) { // -4 end of execution
        if (n == -1) return_book(library); // -1 user returns a book to its corresponding section
        else if (n == -2) delete_books(library); // -2 the personnel takes a certain number of books of a stack
        else write_stack(library); // -3 write stack content
        cin >> n;
    }
}