#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    string s;
    int input, sum = 0, iter = 1;
    for (int i = 0; i < n; i++) {
        while (cin >> input) {
            if (input == x) {
                cout << "La suma de la secuencia " 
                    << iter << " es " << sum << endl;
                sum = 0;
                getline(cin, s);
                ++iter;
            } else 
                sum += input;
        }
    }
}