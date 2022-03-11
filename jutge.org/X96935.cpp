#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st1;

    
    int i = 0;
    while (i < n/2) {
        int x;
        cin >> x;
        st1.push(x);
        ++i;
    }

    if (n % 2 != 0) {
        int erase;
        cin >> erase;
    }

    bool error = false;
    i = 0;
    while (not error and i < n/2) {
        int x;
        cin >> x;
        error = st1.top() != x;
        st1.pop();
        ++i;
    }
    
    if (not error) cout << "SI" << endl;
    else cout << "NO" << endl;
}